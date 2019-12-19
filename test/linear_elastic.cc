#include "catch.hpp"

#include "constitutive/configurations.h"
#include "constitutive/mech/linear_elastic.h"

using namespace constitutive;

TEST_CASE("linear elastic", "[mech]") {
  using config = configs::DealII;
  using MatType LinearElastic<config>;
  LambdaMu<typename config::ParamScalar> elastic_param{100., 60.};
  MatType material{elastic_param};
  SCENARIO("dim  = 1") {
    MatType::SmallStrainState<1> state{};
    state.strain = decltype(state.strain){{{0.1}}};
    material.small_strain_update({}, state);
    ASSERT(state.stress[0][0] = 15.);
  }
}