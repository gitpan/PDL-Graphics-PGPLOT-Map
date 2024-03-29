/*--------------------------------------------------------------------
 *    The GMT-system:	@(#)gmt_project.h	3.40  08/27/99
 *
 *	Copyright (c) 1991-1999 by P. Wessel and W. H. F. Smith
 *	See COPYING file for copying and redistribution conditions.
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; version 2 of the License.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	Contact info: www.soest.hawaii.edu/gmt
 *--------------------------------------------------------------------*/
/*
 * Include file for programs that use the map-projections functions.  Note
 * that most programs will include this by including gmt.h
 *
 * Author:	Paul Wessel
 * Date:	26-FEB-1990
 * Revised:	21-MAY-1998
 *
 */

#define LINEAR		0	/* Linear projections tagged 0-9 */
#define LOG10		1
#define POW		2
#define MERCATOR	10	/* Cylindrical projections tagged 10-99 */
#define	CYL_EQ		11
#define	CYL_EQDIST	12
#define MILLER		13
#define OBLIQUE_MERC	14
#define TM		15
#define UTM		16
#define CASSINI		17
#define STEREO		100	/* Azimuthal projections tagged 100-999 */
#define LAMB_AZ_EQ	101
#define ORTHO		102
#define AZ_EQDIST	103
#define GNOMONIC	104
#define POLAR		110
#define LAMBERT		1000	/* Conic projections tagged 1000-9999 */
#define ALBERS		1001
#define ECONIC		1002
#define MOLLWEIDE	10000	/* Misc projections tagged 10000-99999 */
#define HAMMER		10001
#define SINUSOIDAL	10002
#define WINKEL		10003
#define ROBINSON	10004
#define ECKERT4		10005
#define ECKERT6		10006
#define GRINTEN		10007

#define MAPPING (project_info.projection > 5 || project_info.pars[4] == 1.0)	/* TRUE when map projections are used */
#define CYLINDRICAL (project_info.projection >= 10 && project_info.projection < 100)
#define AZIMUTHAL (project_info.projection >= 100 && project_info.projection < 1000)
#define CONICAL (project_info.projection >= 1000 && project_info.projection < 10000)
#define RECT_GRATICULE (project_info.projection <= MILLER)
#define GRID_CLIP_OK (project_info.projection < 10000 && !AZIMUTHAL)
#define SPHERICAL (gmtdefs.ellipse[gmtdefs.ellipsoid].flattening < 1.0e-10)

#define D2R (M_PI / 180.0)
#define R2D (180.0 / M_PI)

struct MAP_PROJECTIONS {

	double pars[10];		/* Raw unprocessed map-projection parameters as passed on command line */
	double z_pars[2];		/* Raw unprocessed z-projection parameters as passed on command line */
	
	/* Common projection parameters */
	
	int projection;			/* Gives the id number for the projection used */
	
	BOOLEAN x_off_supplied;		/* Used to set xorigin/yorigin for overlay/final plots */
	BOOLEAN y_off_supplied;
	BOOLEAN region_supplied;	/* TRUE when -R option has been given */
	BOOLEAN units_pr_degree;	/* TRUE if scale is given as inch (or cm)/degree.  FALSE for 1:xxxxx */
	BOOLEAN gave_map_width;		/* TRUE if map width in inch (or cm) is given instead of scale.  FALSE for 1:xxxxx */
	BOOLEAN region;			/* TRUE if -R gives lon/lat boundaires, FALSE if it gives lower/left upper right corners */
	BOOLEAN north_pole;		/* TRUE if projection is on northern hermisphere, FALSE on southern */
	BOOLEAN edge[4];		/* TRUE if the edge is a map boundary */
	BOOLEAN three_D;		/* Parameters for 3-D projections */

	double x0, y0, z0;		/* Projected values of the logical origin for the projection */
	double xmin, xmax, ymin, ymax, zmin, zmax;	/* Extreme projected values */
	double w, e, s, n;		/* Bounding geographical region, if applicable */
	double z_bottom, z_top;		/* Bounds in z direction */
	double x_scale, y_scale;	/* Scaling for meters to map-distance (typically inch) conversion */
	double z_scale;			/* Scale for z projection (user-units to map-units (typically inch) */
	double i_x_scale, i_y_scale;	/* Inverse Scaling for meters to map-distance (typically inch) conversion */
	double i_z_scale;		/* Inverse Scale for z projection (user-units to map-units (typically inch) */
	double z_level;			/* Level at which to draw basemap [0] */
	double unit;			/* Gives meters pr plot unit (0.01 or 0.0254) */
	double central_meridian;	/* Central meridian for projection */
	double central_meridian_rad;	/* Same, in radians */
	double pole;			/* +90 pr -90, depending on which pole */
	double EQ_RAD, ECC, ECC2, ECC4, ECC6, M_PR_DEG;	/* Current ellipsoid parameters */
	double half_ECC;		/* 0.5 * ECC */
	double i_half_ECC;		/* 0.5 / ECC */
	double one_m_ECC2;		/* 1.0 - ECC2 */
	double i_EQ_RAD, i_one_m_ECC2;		/* Inverse value */
	
	/* Linear plot parameters */
	
	int xyz_projection[3];		/* For linear projection, 0 = linear, 1 = log10, 2 = pow */
	BOOLEAN xyz_pos[3];		/* TRUE if x,y,z-axis increases in normal positive direction */
	BOOLEAN compute_scale[3];	/* TRUE if axes lengths were set rather than scales */
	double xyz_pow[3];		/* For POW projection */
	double xyz_ipow[3];
	
	/* Mercator parameters.  (See Snyder for details on all parameters) */
	
	double m_m, m_im, m_mx, m_imx;
	BOOLEAN m_got_parallel;		/* TRUE if scale given at lat != 0 */

	/* Center of radii for all conic projections */

	double c_x0, c_y0;

	/* Lambert conformal conic parameters. */
	
	double l_N, l_i_N, l_Nr, l_i_Nr;
	double l_F, l_rF, l_i_rF;
	double l_rho0;
	
	/* Oblique Mercator Projection (Spherical version )*/
	
	double o_sin_pole_lat, o_cos_pole_lat;	/* Pole of rotation */
	double o_pole_lon;	/* In Radians */
	double o_beta;		/* lon' = beta for central_meridian (In Radians) */
	
	/* TM and UTM Projections */

	double t_lat0;
	double t_e2, t_M0;
	double t_c1, t_c2, t_c3, t_c4;
	double t_i1, t_i2, t_i3, t_i4, t_i5;
	
	/* Lambert Azimuthal Equal-Area Projection */
	
	double sinp;
	double cosp;
	double Dx, Dy, iDx, iDy;	/* Fudge factors for projections w/authalic lats */
	
	/* Stereographic Projection */
	
	double s_c, s_ic;
	double r;		/* Radius of projected sphere in plot units (inch or cm) */
	BOOLEAN polar;		/* True if projection pole coincides with S or N pole */
	BOOLEAN s_polar;	/* True if projection pole is S pole */
	BOOLEAN n_polar;	/* True if projection pole is N pole */
	
	/* Mollweide Equal-Area Projection */
	
	double w_x;
	double w_y;
	double w_iy;
	double w_r;	/* Also used by Hammer-Aitoff and Winkel Projections */
	
	/* Winkel Tripel Projection */
	
	double r_cosphi1;	/* = cos (50.467) */
	
	/* Robinson Projection */
	
	double n_cx, n_cy;	/* = = 0.8487R, 1.3523R */
	double n_i_cy;
	double n_phi[19], n_X[19], n_Y[19];
	
	/* Eckert IV Projection */
	
	double k4_x, k4_y, k4_ix, k4_iy;
	
	/* Eckert VI Projection */
	
	double k6_r, k6_ir;
	
	/* Cassini Projection */
	
	double c_M0, c_c1, c_c2, c_c3, c_c4;
	double c_i1, c_i2, c_i3, c_i4, c_i5, c_p;
	
	/* Miller Projection */
	
	double j_x, j_ix, j_y, j_iy;
	
	/* Cylindrical equidistant Projection */
	
	double q_r, q_ir;
	
	/* Cylindrical equal-area Projection(s) */
	
	double y_rx, y_ry;
	double y_i_rx, y_i_ry;
	
	/* Albers Equal-area conic parameters. */
	
	double a_n, a_i_n;
	double a_C, a_n2ir2, a_test, a_Cin;
	double a_rho0;

	/* Equidistant conic parameters. */
	
	double d_n, d_i_n;
	double d_G, d_rho0;

	/* Van der Grinten parameters. */
	
	double v_r, v_ir;

	/* Gnomonic horizon */

	double f_horizon;
	
	/* Polar (cylindrical) projection */

	double p_base_angle;
	
};

struct MAP_FRAME {		/* Various parameters for plotting of map boundaries */
	double frame_int[3];	/* x,y,z */
	double grid_int[3];
	double anot_int[3];
	char label[3][100];	/* Axis label */
	char unit[3][20];	/* Axis unit appended to anotations */
	char header[100];	/* Plot title */
	int side[5];		/* Which sides to plot. 2 is anot/draw, 1 is draw, 0 is not */
	int anot_type[3];	/* For log10 and pow anotations only */
	BOOLEAN plot;		/* TRUE if frame is desired */
	BOOLEAN draw_box;	/* TRUE if 3-D supporting frame is desired */
	BOOLEAN check_side;	/* TRUE if lon and lat anotations should be on x and y axis only */
	BOOLEAN horizontal;	/* TRUE is S/N anotations should be parallel to axes */
};

struct THREE_D {
	double view_azimuth, view_elevation;
	double cos_az, sin_az, cos_el, sin_el;
	double corner_x[4], corner_y[4];
	double xmin, xmax, ymin, ymax;
	double phi[3];		/* Angle each axis makes with horizontal */
	double xshrink[3];	/* Shrinkage in x-dir due to projection */
	double yshrink[3];	/* Same for y-dir */
	double tilt[3];		/* Slant of characters due to projection */
	double sign[4];		/* Used to determine direction of tickmarks etc */
	int quadrant;		/* quandrant we're looking from */
	int z_axis;		/* Which z-axis to draw. */
	int k;			/* For drawing-axis. 0 = plot in x dir, 1 in y */
	int face[3];		/* Tells if this facet has normal in pos direction */
	int draw[4];		/* axes to draw */
};
