# Before `make install' is performed this script should be runnable with
# `make test'. After `make install' it should work as `perl test.pl'

######################### We start with some black magic to print on failure.

# Change 1..1 below to 1..last_test_to_print .
# (It may become useful if the test is moved to ./t subdirectory.)

BEGIN { $| = 1; print "1..4\n"; }
END {print "not ok 1\n" unless $loaded;}
use PDL;
use PDL::Graphics::PGPLOT;
use PDL::Graphics::PGPLOT::Map;
$ENV{PGPLOT_FONT}='/usr/lib/pgplot/grfont.dat';
$loaded = 1;
print "ok 1\n";

######################### End of black magic.

# Insert your test code below (better if it prints "ok 13"
# (correspondingly "not ok 13") depending on the success of chunk 13
# of the test code):

# $ENV{PGPLOT_FONT}='/usr/lib/pgplot/grfont.dat';

my ($lon, $lat) = PDL::Graphics::PGPLOT::Map::fetch({RESOLUTION => 'crude'});

new_window "testmap1.gif/GIF";
line $lon, $lat, {MISSING => -999};
close_window();

my $lat100 = pdl [-999,  79.15938, 79.621118,   79.3608, 80.058747,  78.90547, 79.788663, 79.263752, 79.579919, 79.877165, 79.546654, 78.204471, 78.850538, 78.457771, 78.716258, 78.429389, 78.056764, 77.716182, 77.929198, 77.653315, 77.459525, 77.524224, 76.999924, 76.999924,  76.59617,  78.42237, 78.548714,-999, 80.429236, 80.505531, 80.136263, 80.125887, 79.711147, 79.749905,-999, 78.526741, 78.206912, 78.903639, 78.527352, 78.526741,-999,70, 70.172427, 70.069581, 70.397345, 70.884718, 70.426947, 70.970169, 71.131304, 70.463264, 70.358282, 70.968032, 70.065309, 70.874037, 70.992142,70,-999, 79.749905, 79.802396, 79.452964, 79.181353, 79.943389,  79.94461, 80.346227, 80.103609, 80.504616,  79.97116, 80.429236,-999, 77.623713, 78.253605, 78.113222, 77.438773, 77.614557, 77.237049, 77.623713, 77.623713,-999, 78.204471, 78.612802, 78.480049, 78.205692, 78.204471,-999, 70.970474, 71.097429, 70.970474, 70.970474,-999,  70.33875, 70.621347,  70.33875,  70.33875,-999, 78.838636, 78.907607, 78.838636, 78.838636,-999, 70.266728, 70.334173];

my $tol = 1e-4;
my $ok = (sum(abs($lat100 - $lat->slice("0:100"))) < $tol) ? "ok 2" : "not ok 2";
print "$ok\n";

my @bounds = (-180, 0, -90, 0);
my ($lon, $lat) = PDL::Graphics::PGPLOT::Map::fetch({RESOLUTION => 'low',
                                                     BOX        => \@bounds,
                                                     BOUNDARIES => [1],
                                                     COASTS     => 1,
                                                     SEPARATOR  => -99999});

my $lat100 = pdl [-99999,-2.7933165,-2.8732738,-2.7908751,-2.7933165,-99999, -4.518349, -4.514992,-4.5133135, -4.518349,-99999,-8.5433738,-8.5862516,-8.5412375,-8.5433738,-99999,-9.3299763,-9.3600366,-9.3292134,-9.3299763,-99999,-9.1401541,-9.1880674,-9.1375601,-9.1401541,-99999,-4.6625467,-4.6950484,-4.6575113,-4.6625467,-99999,-4.0016785, -4.010071,-4.0512703, -4.002594,-4.0016785,-99999,-5.6166934,-5.6200504,-5.6154726,-5.6166934,-99999,-9.0159457,-9.0637064,-9.0124361,-9.0159457,-99999,-8.9529259, -8.970016,-8.9529259,-8.9529259,-99999,-9.0733196,-9.1178759,-9.0737774,-9.0733196,-99999,-8.8467231,-8.9645228,-8.8763256, -8.920882,-8.7954528,-8.8358892,-8.8467231,-99999,-9.3841459,-9.4551003,-9.3646143,-9.3824674,-9.3841459,-99999,-8.0024414,-8.0529488,-7.9641413,-8,-8.0024414,-99999,-7.9316396,-7.9082933,-7.9313344,-7.9316396,-99999,-9.6978714,-9.7599756,-9.8329137,-9.8612955,-9.8011749,-9.7442588,-9.6978714,-9.6978714,-99999,-8.9257649,-8.9250019,-8.8679332, -8.924239,-8.9257649,-99999,-10,-9.9424735,-9.8870832,-10];

my $tol = 1e-4;
my $ok = (sum(abs($lat100 - $lat->slice("0:100"))) < $tol) ? "ok 3" : "not ok 3";
print "$ok\n";

new_window "testmap2.gif/GIF";
line $lon, $lat, {MISSING => -99999};
close_window();

my @bounds = (0, 180, 0, 90);
my ($lon, $lat) = PDL::Graphics::PGPLOT::Map::fetch({RESOLUTION => 'low',
                                             BOX        => \@bounds,
                                             BOUNDARIES => [1],
                                             COASTS     => 1,
                                             SEPARATOR  => -99999});


my $lat100 = pdl [-99999,  80.40238, 80.505379, 80.204166,  80.33341, 80.136263,   80.0795, 80.202029, 80.125887, 80.020447, 80.043336,80,-99999, 80.282597, 80.233005, 80.299992, 80.363012, 80.290837, 80.282597,-99999, 80.536202, 80.536202,  80.46952, 80.536049,-99999,80, 80.058747,80,-99999,80, 80.009613,80,-99999,80, 80.150759,  80.15198,  80.27039, 80.241703, 80.346227, 80.243839, 80.314183, 80.347143, 80.269169, 80.278782, 80.121614,  80.19379, 80.103761, 80.420844, 80.504616, 80.311284, 80.416571, 80.396582,80,-99999,80, 80.110018, 80.110018, 80.260777, 80.196231, 80.404974, 80.384527,  80.40238,-99999, 80.128328, 80.135805, 80.141604, 80.128328,-99999, 80.649882, 80.615854, 80.654154, 80.649882,-99999, 80.384222, 80.443732, 80.389258, 80.384222,-99999, 80.668193,  80.67155, 80.674907, 80.668193,-99999, 80.536049, 80.536202, 80.536202,-99999, 80.077058, 80.220035, 80.085756, 80.076295, 80.077058,-99999, 80.132906, 80.171664, 80.132906, 80.132906,-99999, 80.923476, 80.780804, 80.674907];



my $tol = 1e-4;
my $ok = (sum(abs($lat100 - $lat->slice("0:100"))) < $tol) ? "ok 4" : "not ok 4";
print "$ok\n";

# begin PGPLOT section
print "You will need PGPLOT from here on out...\n";
print "The GIF driver must be installed.  Verify that files testmap1.gif through testmap7.gif\n";
print "are created and look reasonable.\n";


new_window "testmap3.gif/GIF";
line $lon, $lat, {MISSING => -99999};
close_window();

new_window "testmap4.gif/GIF";
worldmap ();
close_window();

new_window "testmap5.gif/GIF";
worldmap ({PROJECTION => 'AZEQDIST', # Azimuthal Equidistant projection
           CENTER  => [-170, 70],    # map centered at 170 deg west lon, 70 deg north lat
           RADIUS  => 3000});        # 3000 kilometer minimum radius
close_window();

# equatorial case
new_window "testmap6.gif/GIF";
worldmap ({PROJECTION => 'AZEQDIST', # Azimuthal Equidistant projection
           CENTER  => [-10,  20],    # map centered at 170 deg west lon, 70 deg north lat
           RADIUS  => 3000,          # 3000 kilometer minimum radius
	   RESOLUTION => 'low',
	   LONGRID => 10,            # longitude grid lines every 10 degrees
	   LATGRID => 10});          # latitude grid lines every 10 degrees

# plot projection center point
map_points (pdl([-10]), pdl([20]), {PROJECTION => 'AZEQDIST', CENTER  => [-10,  20], COLOR => 8});
close_window();


# polar case near date line
new_window "testmap7.gif/GIF";
worldmap ({PROJECTION => 'AZEQDIST', # Azimuthal Equidistant projection
           CENTER  => [-170,  80],   # map centered at 170 deg west lon, 80 deg north lat
           RADIUS  => 3000,          # 3000 kilometer minimum radius
	   RESOLUTION => 'low',
	   LONGRID => 20,            # longitude grid lines every 10 degrees
	   LATGRID => 10});          # latitude grid lines every 10 degrees

map_line (pdl(-170, -160), pdl(80, 90), {PROJECTION => 'AZEQDIST', CENTER  => [-170,  80], COLOR => 9});
close_window();

print "Done!\n";











