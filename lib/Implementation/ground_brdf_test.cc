#include "ground_fixture.h"
#include "configuration_fixture.h"
#include "unit_test_support.h"

using namespace FullPhysics;
using namespace blitz;
BOOST_FIXTURE_TEST_SUITE(ground_brdf, GroundFixture)

BOOST_AUTO_TEST_CASE(basic)
{
    // Soil
    BOOST_CHECK_CLOSE(brdf_soil->weight(12987, 0).value(), 0.09480519480566728, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->weight(6192, 1).value(), 0.22476780185770623, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->weight(4854, 2).value(), 0.0786407766991033, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->rahman_factor(0).value(), 0.7, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->rahman_factor(1).value(), 0.8, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->rahman_factor(2).value(), 0.9, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->overall_amplitude(0).value(), 1.0, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->overall_amplitude(1).value(), 1.1, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->overall_amplitude(2).value(), 1.2, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->asymmetry_parameter(0).value(), 1.3, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->asymmetry_parameter(1).value(), 1.4, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->asymmetry_parameter(2).value(), 1.5, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->geometric_factor(0).value(), 1.6, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->geometric_factor(1).value(), 1.7, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->geometric_factor(2).value(), 1.8, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->breon_factor(0).value(), 1.9, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->breon_factor(1).value(), 2.0, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->breon_factor(2).value(), 2.1, 1e-8);

    // Veg
    BOOST_CHECK_CLOSE(brdf_veg->weight(12987, 0).value(), 0.09480519480566728, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->weight(6192, 1).value(), 0.22476780185770623, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->weight(4854, 2).value(), 0.0786407766991033, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->rahman_factor(0).value(), 0.7, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->rahman_factor(1).value(), 0.8, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->rahman_factor(2).value(), 0.9, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->overall_amplitude(0).value(), 1.0, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->overall_amplitude(1).value(), 1.1, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->overall_amplitude(2).value(), 1.2, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->asymmetry_parameter(0).value(), 1.3, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->asymmetry_parameter(1).value(), 1.4, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->asymmetry_parameter(2).value(), 1.5, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->geometric_factor(0).value(), 1.6, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->geometric_factor(1).value(), 1.7, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->geometric_factor(2).value(), 1.8, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->breon_factor(0).value(), 1.9, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->breon_factor(1).value(), 2.0, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->breon_factor(2).value(), 2.1, 1e-8);

    // Soil
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(12987, 0)(0).value(), 0.7*0.09480519480566728, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(6192, 1)(0).value(), 0.8*0.22476780185770623, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(4854, 2)(0).value(), 0.9*0.0786407766991033, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(12987, 0)(1).value(), 1.0, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(6192, 1)(1).value(), 1.1, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(4854, 2)(1).value(), 1.2, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(12987, 0)(2).value(), 1.3, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(6192, 1)(2).value(), 1.4, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(4854, 2)(2).value(), 1.5, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(12987, 0)(3).value(), 1.6, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(6192, 1)(3).value(), 1.7, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(4854, 2)(3).value(), 1.8, 1e-8);

    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(12987, 0)(4).value(), 1.9*0.09480519480566728, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(6192, 1)(4).value(), 2.0*0.22476780185770623, 1e-8);
    BOOST_CHECK_CLOSE(brdf_soil->surface_parameter(4854, 2)(4).value(), 2.1*0.0786407766991033, 1e-8);

    // Veg
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(12987, 0)(0).value(), 0.7*0.09480519480566728, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(6192, 1)(0).value(), 0.8*0.22476780185770623, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(4854, 2)(0).value(), 0.9*0.0786407766991033, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(12987, 0)(1).value(), 1.0, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(6192, 1)(1).value(), 1.1, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(4854, 2)(1).value(), 1.2, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(12987, 0)(2).value(), 1.3, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(6192, 1)(2).value(), 1.4, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(4854, 2)(2).value(), 1.5, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(12987, 0)(3).value(), 1.6, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(6192, 1)(3).value(), 1.7, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(4854, 2)(3).value(), 1.8, 1e-8);

    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(12987, 0)(4).value(), 1.9*0.09480519480566728, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(6192, 1)(4).value(), 2.0*0.22476780185770623, 1e-8);
    BOOST_CHECK_CLOSE(brdf_veg->surface_parameter(4854, 2)(4).value(), 2.1*0.0786407766991033, 1e-8);

}

BOOST_AUTO_TEST_CASE(black_sky_albedo)
{
    double bsa_veg = brdf_veg->black_sky_albedo(0, 0.1);
    // Value calculated in offline tester (same code as in L2, but as an independent program)
    BOOST_CHECK_CLOSE(bsa_veg, -2.82345212639900020046e-02, 1e-10);

    double bsa_soil = brdf_soil->black_sky_albedo(0, 0.1);
    // Value calculated in offline tester (same code as in L2, but as an independent program)
    BOOST_CHECK_CLOSE(bsa_soil, -2.79808069648841521715e-02, 1e-10);
}

BOOST_AUTO_TEST_CASE(albedo)
{
    double spec_idx = 0;
    double sza = 50.0;
    double vza = 45.0;
    double azm = 10.0;
    blitz::Array<double, 1> stokes(4);
    stokes = 0.5, -0.5, 0, 0;

    double alb_veg = brdf_veg->albedo(spec_idx, sza, vza, azm, stokes);
    // Value calculated in offline tester (same code as in L2, but as an independent program)
    BOOST_CHECK_CLOSE(alb_veg, -5.40109310104388944118e-03, 1e-10);

    double alb_soil = brdf_soil->albedo(spec_idx, sza, vza, azm, stokes);
    // Value calculated in offline tester (same code as in L2, but as an independent program)
    BOOST_CHECK_CLOSE(alb_soil, -2.71124317407245817024e-03, 1e-10);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(ground_brdf_veg_config, ConfigurationBrdfVegFixture)

BOOST_AUTO_TEST_CASE(load_from_lua)
{
    for(int spec_idx = 0; spec_idx < 3; spec_idx++) {
        // These parameters do not vary by band number or wavenumber
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(0).value(), 1.0, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(1).value(), 0.05, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(2).value(), -0.1, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(3).value(), 0.75, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(4).value(), 1.0, 1e-8);
    }
}

 
BOOST_AUTO_TEST_SUITE_END()


BOOST_FIXTURE_TEST_SUITE(ground_brdf_soil_config, ConfigurationBrdfVegFixture)

BOOST_AUTO_TEST_CASE(load_from_lua)
{
    for(int spec_idx = 0; spec_idx < 3; spec_idx++) {
        // These parameters do not vary by band number or wavenumber
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(0).value(), 1.0, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(1).value(), 0.05, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(2).value(), -0.1, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(3).value(), 0.75, 1e-8);
        BOOST_CHECK_CLOSE(config_ground->surface_parameter(13000, spec_idx)(4).value(), 1.0, 1e-8);
    }
}

BOOST_AUTO_TEST_SUITE_END()

