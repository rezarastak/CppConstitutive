#pragma once

namespace constitutive {
/**
 * Parameters used to describe the basic elastisicy of materials.
 * It stores the Lam{\'e} constants.
 */
template <typename Param = double> struct ElasticParams {
  /**
   * The Lam{\'e} stiffness constant $\lambda$.
   */
  Param lambda;

  /**
   * The Lam{\'e} shear constant $\mu$.
   */
  Param mu;

  /**
   * This is used as a constructor.
   */
  static ElasticParams from_lambda_and_mu(Param lambda, Param mu);
};
} // namespace constitutive