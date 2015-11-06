#include "stdafx.h"

#include "PrimeEngine/Pathfinding/AStar.h"

#include "PrimeEngine/Pathfinding/Navmesh.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;
using namespace Pathfinding;

namespace PathfindingTests
{
	[TestClass]
	public ref class UnitTest
	{
	private:
		TestContext^ testContextInstance;

	public: 
		/// <summary>
		///Gets or sets the test context which provides
		///information about and functionality for the current test run.
		///</summary>
		property Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ TestContext
		{
			Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ get()
			{
				return testContextInstance;
			}
			System::Void set(Microsoft::VisualStudio::TestTools::UnitTesting::TestContext^ value)
			{
				testContextInstance = value;
			}
		};

		#pragma region Additional test attributes
		//
		//You can use the following additional attributes as you write your tests:
		//
		//Use ClassInitialize to run code before running the first test in the class
		//[ClassInitialize()]
		//static void MyClassInitialize(TestContext^ testContext) {};
		//
		//Use ClassCleanup to run code after all tests in a class have run
		//[ClassCleanup()]
		//static void MyClassCleanup() {};
		//
		//Use TestInitialize to run code before running each test
		//[TestInitialize()]
		//void MyTestInitialize() {};
		//
		//Use TestCleanup to run code after each test has run
		//[TestCleanup()]
		//void MyTestCleanup() {};
		//
		#pragma endregion 

        // TODO: clean up init code by putting it in region above because they all share the same one

		[TestMethod]
		void TestConvexPolygon()
		{
            ConvexPolygon* p = new ConvexPolygon();
            Vector3* v0 = new Vector3(0, 0, 0);
            Vector3* v1 = new Vector3(1, 0, 0);
            Vector3* v2 = new Vector3(0, 1, 0);
            p->vertices.push_back(v2);
            p->vertices.push_back(v1);
            p->vertices.push_back(v0);

            ConvexPolygon* neighbour1 = new ConvexPolygon();
            Vector3* v3 = new Vector3(1, 1, 0);
            neighbour1->neighbours.push_back(p);
            neighbour1->vertices.push_back(v3);
            neighbour1->vertices.push_back(v1);
            neighbour1->vertices.push_back(v2);

            p->neighbours.push_back(neighbour1);

            // verify the vertices data structure
            Assert::IsTrue(*(p->vertices.at(0)) == *v2);
            Assert::IsTrue(*(neighbour1->vertices.at(0)) == *v3);

            // verify the neighbour data structure
            Assert::IsTrue(*(p->neighbours.at(0)) == *neighbour1);
            Assert::IsTrue(*(neighbour1->neighbours.at(0)) == *p);

            // temporary: just to test the getters / setters
            Vector3* fake_centre = new Vector3(9, 9, 0);
            p->setCentre(fake_centre);
            Assert::IsTrue(*fake_centre == *(p->getCentre()));

            delete fake_centre;
            delete v0;
            delete v1;
            delete v2;
            delete v3;
            
            delete neighbour1;
            delete p;
		};

        [TestMethod]
        void TestPolygonInside()
        {
            ConvexPolygon* p = new ConvexPolygon();
            Vector3* v0 = new Vector3(0, 0, 0);
            Vector3* v1 = new Vector3(1, 0, 0);
            Vector3* v2 = new Vector3(0, 1, 0);
            p->vertices.push_back(v2);
            p->vertices.push_back(v1);
            p->vertices.push_back(v0);

            Vector3* pt = new Vector3(0.25, 0.25, 0);

            Assert::IsTrue(p->IsInside(pt));

            delete v0;
            delete v1;
            delete v2;
            delete p;
            delete pt;
        }

        [TestMethod]
        void TestNode()
        {
            ConvexPolygon* p = new ConvexPolygon();
            Vector3* p_c = new Vector3(0.25, 0.25, 0); // approximation
            Vector3* v0 = new Vector3(0, 0, 0);
            Vector3* v1 = new Vector3(1, 0, 0);
            Vector3* v2 = new Vector3(0, 1, 0);
            p->vertices.push_back(v2);
            p->vertices.push_back(v1);
            p->vertices.push_back(v0);
            p->setCentre(p_c);

            ConvexPolygon* neighbour1 = new ConvexPolygon();
            Vector3* n1_c = new Vector3(0.75, 0.75, 0); // approximation
            Vector3* v3 = new Vector3(1, 1, 0);
            neighbour1->neighbours.push_back(p);
            neighbour1->vertices.push_back(v3);
            neighbour1->vertices.push_back(v1);
            neighbour1->vertices.push_back(v2);
            neighbour1->setCentre(n1_c);

            p->neighbours.push_back(neighbour1);

            AStarNode* entry = new AStarNode(p);
            
            // test equals for node
            Assert::IsTrue(*entry == *entry);

            delete p_c;
            delete n1_c;
            delete v0;
            delete v1;
            delete v2;
            delete v3;

            delete neighbour1;
            delete p;
            delete entry;
        }

        [TestMethod]
        void TestAStar2Node()
        {
            ConvexPolygon* p = new ConvexPolygon();
            Vector3* p_c = new Vector3(0.25, 0.25, 0); // approximation
            Vector3* v0 = new Vector3(0, 0, 0);
            Vector3* v1 = new Vector3(1, 0, 0);
            Vector3* v2 = new Vector3(0, 1, 0);
            p->vertices.push_back(v2);
            p->vertices.push_back(v1);
            p->vertices.push_back(v0);
            p->setCentre(p_c);

            ConvexPolygon* neighbour1 = new ConvexPolygon();
            Vector3* n1_c = new Vector3(0.75, 0.75, 0); // approximation
            Vector3* v3 = new Vector3(1, 1, 0);
            neighbour1->neighbours.push_back(p);
            neighbour1->vertices.push_back(v3);
            neighbour1->vertices.push_back(v1);
            neighbour1->vertices.push_back(v2);
            neighbour1->setCentre(n1_c);

            p->neighbours.push_back(neighbour1);

            std::vector<AStarNode*> open_list, closed_list;
            Vector3* goal = new Vector3(0.8, 0.8, 0);

            // a-star setup that will be accomplished in another function later
            AStarNode* entry = new AStarNode(p);

            open_list.push_back(entry);

            a_star(goal, &open_list, &closed_list);

            // test that open list is empty
            Assert::IsTrue(open_list.size() == 0);

            // test that closed list is properly ordered
            Assert::IsTrue(closed_list.size() == 2);
            Assert::IsTrue(*closed_list.at(0) == *entry);
            Assert::IsTrue(*closed_list.at(1)->parent == *entry);

            for each (AStarNode* n in open_list)  {
                delete n;
            }
            for each (AStarNode* n in closed_list)  {
                delete n;
            }

            delete p_c;
            delete n1_c;
            delete v0;
            delete v1;
            delete v2;
            delete v3;

            delete neighbour1;
            delete p;
        };

        [TestMethod]
        void TestAStarMultipleNodes()
        {
            std::vector<AStarNode*> open_list, closed_list;
            std::vector<ConvexPolygon*> all_polys;

            const int GRID_SIZE = 4;
            for (int j = 0; j < GRID_SIZE; j++) {
                for (int i = 0; i < GRID_SIZE; i++) {

                    ConvexPolygon* p = new ConvexPolygon();
                    p->vertices.push_back(new Vector3(i, j + 1, 0));
                    p->vertices.push_back(new Vector3(i + 1, j + 1, 0));
                    p->vertices.push_back(new Vector3(i + 1, j, 0));
                    p->vertices.push_back(new Vector3(i, j, 0));
                    p->setCentre(new Vector3(i + 0.5, j + 0.5, 0));

                    if (i > 0) {
                        p->neighbours.push_back(all_polys.at(i-1+GRID_SIZE*j));
                        all_polys.at(i - 1 + GRID_SIZE*j)->neighbours.push_back(p);
                    }
                    if (j > 0) {
                        p->neighbours.push_back(all_polys.at(i + GRID_SIZE*(j-1)));
                        all_polys.at(i + GRID_SIZE*(j - 1))->neighbours.push_back(p);
                    }

                    all_polys.push_back(p);
                    
                }
            }

            Vector3* goal = new Vector3(3.9, 3.9, 0);

            // a-star setup that will be accomplished in another function later
            AStarNode* entry = new AStarNode(all_polys.at(0));

            open_list.push_back(entry);

            a_star(goal, &open_list, &closed_list);


            // test that closed list is properly ordered
            Assert::IsTrue(closed_list.size() == 7);
            Assert::IsTrue(*closed_list.at(0) == *entry);
            Assert::IsTrue(*closed_list.at(1)->parent == *entry);
            Assert::IsTrue(Math::Abs(closed_list.at(6)->polygon->getCentre()->getX() - 3.5) < 0.001 );


            // this is probably what
            // garbage collection for nav-mesh
            // looks like
            for each (ConvexPolygon* p in all_polys)
            {
                for each (Vector3* v in p->vertices)
                {
                    if (v != NULL)
                        delete v;
                }
                delete p->getCentre();
                delete p;
            }
            delete goal;
            for each (AStarNode* n in open_list)  {
                delete n;
            }
            for each (AStarNode* n in closed_list)  {
                delete n;
            }
        };


        [TestMethod]
        void TestBasicMeshSubdivision()
        {
            Pathfinding::Polygon* poly = new Pathfinding::Polygon();

            // clockwise
            Vector3* p0 = new Vector3(0, 1, 0);
            Vector3* p1 = new Vector3(1, 1, 0);
            Vector3* p2 = new Vector3(1, 0, 0);
            Vector3* p3 = new Vector3(0, 0, 0);


            poly->vertices.push_back(p0);
            poly->vertices.push_back(p1);
            poly->vertices.push_back(p2);
            poly->vertices.push_back(p3);

            Navmesh* navmesh = new Navmesh();
            Assert::IsTrue(navmesh->GenerateNavmesh(poly));

            Assert::IsTrue(navmesh->mesh.size() == 1);
            Assert::IsTrue(navmesh->mesh.at(0)->vertices.size() == 4);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(0) == *p0);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(1) == *p1);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(2) == *p2);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(3) == *p3);

            delete navmesh;
        };

        [TestMethod]
        void TestAdvancedMeshSubdivision()
        {
            Pathfinding::Polygon* poly = new Pathfinding::Polygon();

            // clockwise
            Vector3* p0 = new Vector3(0, 1, 0);
            Vector3* p1 = new Vector3(0.5, 0.3, 0);
            Vector3* p2 = new Vector3(1, 1, 0);
            Vector3* p3 = new Vector3(1, 0, 0);
            Vector3* p4 = new Vector3(0, 0, 0);


            poly->vertices.push_back(p0);
            poly->vertices.push_back(p1);
            poly->vertices.push_back(p2);
            poly->vertices.push_back(p3);
            poly->vertices.push_back(p4);

            Navmesh* navmesh = new Navmesh();
            Assert::IsTrue(navmesh->GenerateNavmesh(poly));

            // this should be split into 3 parts


            Assert::IsTrue(navmesh->mesh.size() == 2);

            /*
            Assert::IsTrue(navmesh->mesh.at(0)->vertices.size() == 5);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(0) == *p0);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(1) == *p1);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(2) == *p2);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(3) == *p3);
            Assert::IsTrue(*navmesh->mesh.at(0)->vertices.at(4) == *p4);
            */

            delete navmesh;
        };
	};
}
