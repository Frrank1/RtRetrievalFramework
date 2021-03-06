#include "ecmwf_pass_through_output.h"
#include "fp_exception.h"

// This won't be needed once version 3 becomes the default for boost filesystem
#define BOOST_FILESYSTEM_VERSION 3
#include <boost/filesystem.hpp>

using namespace FullPhysics;

#ifdef HAVE_LUA
#include "register_lua.h"
REGISTER_LUA_DERIVED_CLASS(EcmwfPassThroughOutput, RegisterOutputBase)
.def(luabind::constructor<const boost::shared_ptr<Ecmwf>&>())
REGISTER_LUA_END()
#endif

void EcmwfPassThroughOutput::register_output(const boost::shared_ptr<Output>& out) const
{
    out->register_data_source
        ("/RetrievalResults/windspeed_u_ecmwf", &Ecmwf::windspeed_u, ecmwf_);

    out->register_data_source
        ("/RetrievalResults/windspeed_v_ecmwf", &Ecmwf::windspeed_v, ecmwf_);
}
