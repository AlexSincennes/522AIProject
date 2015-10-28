#include "stdafx.h"

#include "PrimeEngine/Pathfinding/AStar.h"

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
        }

        [TestMethod]
        void TestAStar()
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
	};
}
