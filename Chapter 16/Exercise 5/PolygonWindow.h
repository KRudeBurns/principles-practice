// -----------------------------------------------------------------------------
#ifndef POLYGONWINDOW_H_
#define POLYGONWINDOW_H_
// -----------------------------------------------------------------------------

//----INCLUDES----//
#include "GUI.h"

// -----------------------------------------------------------------------------

namespace Graph_lib
{
	// -----------------------------------------------------------------------------

	const int NO_NUMBER_GIVEN = -999999;

	// PolygonWindow is a simple window that draws polygons at given coordinates and 
	// sizes

	struct PolygonWindow : public Window
	{
	public:
		PolygonWindow(Point xy, int w, int h, const char* title);

		Point xy() const { return m_xy; }

	private:
		enum PolygonType {
			circle, square, eqTriangle, hexagon
		};

		// actions
		void onQuitPressed();
		void onNextPressed();
		void onCreatePolygon(PolygonType pt);

		// objects
		vector<Shape*> mv_shapes;
		Star m_starShape;
		Menu m_polygonM;
		Button m_quitB, m_nextB;
		In_box m_xIn, m_yIn, m_sizeIn;
		
		// member variables
		Point m_xy;
	};

}  // namespace Graph_lib

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

#endif // !POLYGONWINDOW_H_
