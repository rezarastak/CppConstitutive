#include "catch.hpp"

#include "constitutive/mech/elastic.h"

using namespace constitutive;

TEST_CASE("Elastic params (lambda, mu)", "[mech]") {
  LambdaMu lambda_mu{100., 50.};
  REQUIRE(lambda_mu.get_lambda() == 100.);
  REQUIRE(lambda_mu.get_mu() == 50.);
  REQUIRE(lambda_mu.get_E() == Approx(133.3).epsilon(0.01));
  REQUIRE(lambda_mu.get_nu() == Approx(0.33).margin(0.01));
}

TEST_CASE("Elastic params (E, nu)", "[mech]") {
  YoungPoisson params{120., 0.25};
  REQUIRE(params.get_E() == 120.);
  REQUIRE(params.get_nu() == 0.25);
  REQUIRE(params.get_lambda() == 48.);
  REQUIRE(params.get_mu() == 48.);
}

TEST_CASE("Convert lambda, mu to E, nu", "[mech]") {
  LambdaMu lambda_mu(80., 60.);
  YoungPoisson young_poisson(lambda_mu);
  REQUIRE(young_poisson.get_E() == Approx(154.3).epsilon(0.01));
  REQUIRE(young_poisson.get_nu() == Approx(0.29).margin(0.01));
}

TEST_CASE("Convert E, nu to lambda, mu", "[mech]") {
  YoungPoisson young_poisson{100., 0.35};
  LambdaMu lambda_mu{young_poisson};
  REQUIRE(lambda_mu.get_lambda() == Approx(86.4).epsilon(0.01));
  REQUIRE(lambda_mu.get_mu() == Approx(37.).epsilon(0.01));
}
