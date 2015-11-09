#include "Polygon.h"

namespace Pathfinding {

    Polygon::Polygon()
    {
    }


    Polygon::~Polygon()
    {
    }

	void CreatePolygonMesh()
	{
		{
			Polygon* p = new Polygon();
			Vector3* v2 = new Vector3(954.004, 0, 904.308);
			Vector3* v1 = new Vector3(738.720, 0, 555.027);
			Vector3* v0 = new Vector3(512.114, 1, 911.350);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);

			
		}
		{
		Polygon* p2 = new Polygon();
		Vector3* v0 = new Vector3(738.720, 0, 555.027);
		Vector3* v1 = new Vector3(472.280, 0, 190.286);
		Vector3* v2 = new Vector3(882.390, 1, 192.018);
		p2->vertices.push_back(v2);
		p2->vertices.push_back(v1);
		p2->vertices.push_back(v0);
	}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(472.280, 0, 190.286);
			Vector3* v1 = new Vector3(686.701, 0, -92.551);
			Vector3* v2 = new Vector3(882.390, 1, 192.018);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(686.701, 0, -92.551);
			Vector3* v1 = new Vector3(387.140, 0, -427.960);
			Vector3* v2 = new Vector3(847.352, 1, -381.680);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(387.140, 0, -427.960);
			Vector3* v1 = new Vector3(260.946, 0, -157.370);
			Vector3* v2 = new Vector3(0, 0, -479.723);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-154.424, 0, -165.375);
			Vector3* v1 = new Vector3(-397.483, 0, -430.620);
			Vector3* v2 = new Vector3(0, 0, -479.723);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-397.483, 0, -430.620);
			Vector3* v1 = new Vector3(-154.424, 0, -165.375);
			Vector3* v2 = new Vector3(-579.248, 0, -158.669);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-397.483, 0, -430.620);
			Vector3* v1 = new Vector3(-579.248, 0, -158.669);
			Vector3* v2 = new Vector3(-688.497, 0, -752.401);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-397.483, 0, -430.620);
			Vector3* v1 = new Vector3(-688.497, 0, -752.401);
			Vector3* v2 = new Vector3(0, 0, -479.723);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(0, 0, -479.723);
			Vector3* v1 = new Vector3(-255.569, 0, -740.652);
			Vector3* v2 = new Vector3(140.036, 0, -720.692);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(140.036, 0, -720.692);
			Vector3* v1 = new Vector3(-255.569, 0, -740.652);
			Vector3* v2 = new Vector3(344.311, 0, -1013.399);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(344.311, 0, -1013.399);
			Vector3* v1 = new Vector3(-910.474, 0, -1077.840);
			Vector3* v2 = new Vector3(640.455, 0, -691.717);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(640.455, 0, -691.717);
			Vector3* v1 = new Vector3(140.036, 0, -720.692);
			Vector3* v2 = new Vector3(344.311, 0, -1013.399);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(910.474, 0, -1077.840);
			Vector3* v1 = new Vector3(344.311, 0, -1013.399);
			Vector3* v2 = new Vector3(578.943, 0, -1660.360);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(578.943, 0, -1660.360);
			Vector3* v1 = new Vector3(344.311, 0, -1013.399);
			Vector3* v2 = new Vector3(-116.295, 0, -1564.534);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(344.311, 0, -1013.399);
			Vector3* v1 = new Vector3(-255.569, 0, -740.652);
			Vector3* v2 = new Vector3(-116.295, 0, -1564.534);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-688.497, 0, -752.401);
			Vector3* v1 = new Vector3(-441.331, 0, -1238.179);
			Vector3* v2 = new Vector3(-255.569, 0, -740.652);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-116.295, 0, -1564.534);
			Vector3* v1 = new Vector3(-441.331, 0, -1238.179);
			Vector3* v2 = new Vector3(-728.599, 0, -1788.843);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-728.599, 0, -1788.843);
			Vector3* v1 = new Vector3(-1303.138, 0, -1300.418);
			Vector3* v2 = new Vector3(-1429.024, 0, -1871.689);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-441.331, 0, -1238.179);
			Vector3* v1 = new Vector3(-728.599, 0, -1788.843);
			Vector3* v2 = new Vector3(-1303.138, 0, -1300.418);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-1560.167, 0, -516.492);
			Vector3* v1 = new Vector3(-1303.138, 0, -1300.418);
			Vector3* v2 = new Vector3(-688.497, 0, -752.401);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		//-579.248, 0, -158.669)
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-579.248, 0, -158.669);
			Vector3* v1 = new Vector3(-1668.404, 0, 0);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-1668.404, 0, 0);
			Vector3* v1 = new Vector3(-2667.751, 0, 0);
			Vector3* v2 = new Vector3(-1303.138, 0, -1300.418);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v1 = new Vector3(-1303.138, 0, -1300.418);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-1668.404, 0, 0);
			Vector3* v2 = new Vector3(-2667.751, 0, 0);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v2 = new Vector3(-1560.167, 0, -516.492);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2426.662, 0, -527.987);
			Vector3* v1 = new Vector3(-2667.751, 0, 0);
			Vector3* v2 = new Vector3(-3643.565, 0, -284.952);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-3643.565, 0, -284.952);
			Vector3* v1 = new Vector3(-2763.366, 0, -1328.292);
			Vector3* v2 = new Vector3(-2426.662, 0, -527.987);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2581.175, 0, -2006.472);
			Vector3* v1 = new Vector3(-1429.024, 0, -1871.689);
			Vector3* v2 = new Vector3(-2763.366, 0, -1328.292);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-3460.386, 0, -1481.354);
			Vector3* v1 = new Vector3(-2581.175, 0, -2006.472);
			Vector3* v2 = new Vector3(-2763.366, 0, -1328.292);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(146.001, 0, -2368.225);
			Vector3* v1 = new Vector3(1021.650, 0, -2325.321);
			Vector3* v2 = new Vector3(578.943, 0, -1660.360);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(146.001, 0, -2368.225);
			Vector3* v1 = new Vector3(578.943, 0, -1660.360);
			Vector3* v2 = new Vector3(-728.599, 0, -1788.843);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-918.597, 0, -2741.241);
			Vector3* v1 = new Vector3(146.001, 0, -2368.225);
			Vector3* v2 = new Vector3(-728.599, 0, -1788.843);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-918.597, 0, -2741.241);
			Vector3* v1 = new Vector3(-728.599, 0, -1788.843);
			Vector3* v2 = new Vector3(-1429.024, 0, -1871.689);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v1 = new Vector3(-918.597, 0, -2741.241);
			Vector3* v2 = new Vector3(-1429.024, 0, -1871.689);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v1 = new Vector3(-1429.024, 0, -1871.689);
			Vector3* v2 = new Vector3(-2581.175, 0, -2006.472);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-3391.240, 0, -2391.356);
			Vector3* v1 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v2 = new Vector3(-2581.175, 0, -2006.472);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2985.163, 0, -3169.880);
			Vector3* v1 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v2 = new Vector3(-3391.240, 0, -2391.356);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v1 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v2 = new Vector3(-2985.163, 0, -3169.880);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-2215.451, 0, -2657.615);
			Vector3* v1 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v2 = new Vector3(-918.597, 0, -2741.241);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(526.426, 0, -2951.756);
			Vector3* v1 = new Vector3(1021.650, 0, -2325.321);
			Vector3* v2 = new Vector3(146.001, 0, -2368.225);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(839.598, 0, -3708.078);
			Vector3* v1 = new Vector3(526.426, 0, -2325.321);
			Vector3* v2 = new Vector3(0, 0, -3843.365);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(526.426, 0, -2325.321);
			Vector3* v1 = new Vector3(839.598, 0, -3708.078);		
			Vector3* v2 = new Vector3(1021.650, 0, -2325.321);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(146.001, 0, -2368.225);
			Vector3* v1 = new Vector3(0, 0, -3843.365);
			Vector3* v2 = new Vector3(526.426, 0, -2325.321);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v1 = new Vector3(0, 0, -3843.365);
			Vector3* v2 = new Vector3(-918.597, 0, -2741.241);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-1945.901, 0, -4071.808);
			Vector3* v1 = new Vector3(0, 0, -3843.365);
			Vector3* v2 = new Vector3(-1710.603, 0, -3154.453);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}

		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-1710.603, 0, -3154.453);
			Vector3* v1 = new Vector3(-2985.163, 0, -3169.880);
			Vector3* v2 = new Vector3(-1945.901, 0, -4071.808);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
		{
			Polygon* p = new Polygon();
			Vector3* v0 = new Vector3(-3336.958, 0, -4053.486);
			Vector3* v1 = new Vector3(-1945.901, 0, -4071.808);
			Vector3* v2 = new Vector3(-1710.603, 0, -3154.453);
			p->vertices.push_back(v2);
			p->vertices.push_back(v1);
			p->vertices.push_back(v0);
		}
	}
}
