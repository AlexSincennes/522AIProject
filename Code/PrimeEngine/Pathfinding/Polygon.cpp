#include "Polygon.h"
#include "Navmesh.h"
namespace Pathfinding {

    Polygon::Polygon()
    {
    }


    Polygon::~Polygon()
    {
    }

	void Polygon::CreatePolygonMesh()
	{
        // we use X and Y for the mesh --> transform z to y

        // also I don't know why any Y values are used here

        // basically, I want you to create a mesh which defines the
        // traversable areas of the map as a convex polygons
		Navmesh* navmesh = new Navmesh();
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v2 = new Vector3(9.54004, 0, 9.04308);
			Vector3* v1 = new Vector3(7.38720, 0, 5.55027);
			Vector3* v0 = new Vector3(5.12114, 1, 9.11350);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);

			
		}
		{
			ConvexPolygon* p2 = new ConvexPolygon();
		Vector3* v0 = new Vector3(7.38720, 0, 5.55027);
		Vector3* v1 = new Vector3(4.72280, 0, 1.90286);
		Vector3* v2 = new Vector3(8.82390, 1, 1.92018);
		p2->vertices.push_back(v2);
		p2->vertices.push_back(v1);
		p2->vertices.push_back(v0);
		navmesh->mesh.push_back(p2);
	}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(4.72280, 0, 1.90286);
			Vector3* v1 = new Vector3(6.86701, 0, -0.92551);
			Vector3* v2 = new Vector3(8.82390, 1, 1.92018);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(6.86701, 0, -0.92551);
			Vector3* v1 = new Vector3(3.87140, 0, -4.27960);
			Vector3* v2 = new Vector3(8.47352, 1, -3.81680);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(3.87140, 0, -4.27960);
			Vector3* v1 = new Vector3(2.60946, 0, -1.57370);
			Vector3* v2 = new Vector3(0, 0, -4.79723);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-1.54424, 0, -1.65375);
			Vector3* v1 = new Vector3(-3.97483, 0, -4.30620);
			Vector3* v2 = new Vector3(0, 0, -4.79723);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-3.97483, 0, -4.30620);
			Vector3* v1 = new Vector3(-1.54424, 0, -1.65375);
			Vector3* v2 = new Vector3(-5.79248, 0, -1.58669);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-3.97483, 0, -4.30620);
			Vector3* v1 = new Vector3(-5.79248, 0, -1.58669);
			Vector3* v2 = new Vector3(-6.88497, 0, -7.52401);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-3.97483, 0, -4.30620);
			Vector3* v1 = new Vector3(-6.88497, 0, -7.52401);
			Vector3* v2 = new Vector3(0, 0, -4.79723);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(0, 0, -4.79723);
			Vector3* v1 = new Vector3(-2.55569, 0, -7.40652);
			Vector3* v2 = new Vector3(1.40036, 0, -7.20692);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(1.40036, 0, -7.20692);
			Vector3* v1 = new Vector3(-2.55569, 0, -7.40652);
			Vector3* v2 = new Vector3(3.44311, 0, -10.13399);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(3.44311, 0, -10.13399);
			Vector3* v1 = new Vector3(-9.10474, 0, -10.77840);
			Vector3* v2 = new Vector3(6.40455, 0, -6.91717);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(6.40455, 0, -6.91717);
			Vector3* v1 = new Vector3(1.40036, 0, -7.20692);
			Vector3* v2 = new Vector3(3.44311, 0, -10.13399);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(9.10474, 0, -10.77840);
			Vector3* v1 = new Vector3(3.44311, 0, -10.13399);
			Vector3* v2 = new Vector3(5.78943, 0, -16.60360);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(5.78943, 0, -16.60360);
			Vector3* v1 = new Vector3(3.44311, 0, -10.13399);
			Vector3* v2 = new Vector3(-1.16295, 0, -15.64534);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(3.44311, 0, -10.13399);
			Vector3* v1 = new Vector3(-2.55569, 0, -7.40652);
			Vector3* v2 = new Vector3(-1.16295, 0, -15.64534);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		
	/*	{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-688.497, 0, -752.401);
			Vector3* v1 = new Vector3(-441.331, 0, -1238.179);
			Vector3* v2 = new Vector3(-255.569, 0, -740.652);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-116.295, 0, -1564.534);
			Vector3* v1 = new Vector3(-441.331, 0, -1238.179);
			Vector3* v2 = new Vector3(-728.599, 0, -1788.843);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-728.599, 0, -1788.843);
			Vector3* v1 = new Vector3(-1303.138, 0, -1300.418);
			Vector3* v2 = new Vector3(-1429.024, 0, -1871.689);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-441.331, 0, -1238.179);
			Vector3* v1 = new Vector3(-728.599, 0, -1788.843);
			Vector3* v2 = new Vector3(-1303.138, 0, -1300.418);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-1560.167, 0, -516.492);
			Vector3* v1 = new Vector3(-1303.138, 0, -1300.418);
			Vector3* v2 = new Vector3(-688.497, 0, -752.401);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		//-579.248, 0, -158.669)
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-579.248, 0, -158.669);
			Vector3* v1 = new Vector3(-1668.404, 0, 0);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-1668.404, 0, 0);
			Vector3* v1 = new Vector3(-2667.751, 0, 0);
			Vector3* v2 = new Vector3(-1303.138, 0, -1300.418);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v1 = new Vector3(-1303.138, 0, -1300.418);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-1668.404, 0, 0);
			Vector3* v2 = new Vector3(-2667.751, 0, 0);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-2667.751, 0, 0);
			Vector3* v2 = new Vector3(-3643.565, 0, -284.952);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-3643.565, 0, -284.952);
			Vector3* v1 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v2 = new Vector3(-2426.662, 0, -527.987);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2581.175, 0, -2006.472);
			Vector3* v1 = new Vector3(-1429.024, 0, -1871.689);
			Vector3* v2 = new Vector3(-2763.366, 0, -1328.292);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-3460.386, 0, -1481.354);
			Vector3* v1 = new Vector3(-2581.175, 0, -2006.472);
			Vector3* v2 = new Vector3(-2763.366, 0, -1328.292);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(146.001, 0, -2368.225);
			Vector3* v1 = new Vector3(1021.650, 0, -2325.321);
			Vector3* v2 = new Vector3(578.943, 0, -1660.360);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(146.001, 0, -2368.225);
			Vector3* v1 = new Vector3(578.943, 0, -1660.360);
			Vector3* v2 = new Vector3(-728.599, 0, -1788.843);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-918.597, 0, -2741.241);
			Vector3* v1 = new Vector3(146.001, 0, -2368.225);
			Vector3* v2 = new Vector3(-728.599, 0, -1788.843);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-918.597, 0, -2741.241);
			Vector3* v1 = new Vector3(-728.599, 0, -1788.843);
			Vector3* v2 = new Vector3(-1429.024, 0, -1871.689);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v1 = new Vector3(-918.597, 0, -2741.241);
			Vector3* v2 = new Vector3(-1429.024, 0, -1871.689);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v1 = new Vector3(-1429.024, 0, -1871.689);
			Vector3* v2 = new Vector3(-2581.175, 0, -2006.472);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-3391.240, 0, -2391.356);
			Vector3* v1 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v2 = new Vector3(-2581.175, 0, -2006.472);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2985.163, 0, -3169.880);
			Vector3* v1 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v2 = new Vector3(-3391.240, 0, -2391.356);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v1 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v2 = new Vector3(-2985.163, 0, -3169.880);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v1 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v2 = new Vector3(-918.597, 0, -2741.241);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(526.426, 0, -2951.756);
			Vector3* v1 = new Vector3(1021.650, 0, -2325.321);
			Vector3* v2 = new Vector3(146.001, 0, -2368.225);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(839.598, 0, -3708.078);
			Vector3* v1 = new Vector3(526.426, 0, -2325.321);
			Vector3* v2 = new Vector3(0, 0, -3843.365);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(526.426, 0, -2325.321);
			Vector3* v1 = new Vector3(839.598, 0, -3708.078);		
			Vector3* v2 = new Vector3(1021.650, 0, -2325.321);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(146.001, 0, -2368.225);
			Vector3* v1 = new Vector3(0, 0, -3843.365);
			Vector3* v2 = new Vector3(526.426, 0, -2325.321);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v1 = new Vector3(0, 0, -3843.365);
			Vector3* v2 = new Vector3(-918.597, 0, -2741.241);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-1945.901, 0, -4071.808);
			Vector3* v1 = new Vector3(0, 0, -3843.365);
			Vector3* v2 = new Vector3(-1710.603, 0, -3154.453);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}

		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v1 = new Vector3(-2985.163, 0, -3169.880);
			Vector3* v2 = new Vector3(-1945.901, 0, -4071.808);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}
		{
			ConvexPolygon* p = new ConvexPolygon();
			Vector3* v0 = new Vector3(-3336.958, 0, -4053.486);
			Vector3* v1 = new Vector3(-1945.901, 0, -4071.808);
			Vector3* v2 = new Vector3(-1710.603, 0, -3154.453);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
			navmesh->mesh.push_back(p);
		}*/
	}
}
