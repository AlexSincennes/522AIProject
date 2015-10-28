#include "stdafx.h"

#include "PrimeEngine/Pathfinding/ConvexPolygon.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace Microsoft::VisualStudio::TestTools::UnitTesting;

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
        void TestAStar()
        {
            //
            // TODO: Add test logic here
            //
        };
	};
}
