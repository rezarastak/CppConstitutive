#pragma once

#include <constitutive/mech/elastic.h>

namespace constitutive {
/**
 * Linear Elastic material.
 * Since this class has only one data member, it does not need a constructor.
 * @tparam Config: provides type information for various struct and state
 * data.
 */
template <typename Config>
struct LinearElastic {
  /**
   * Elastic parameters describing the material.
   */
  LambdaMu<typename Config::ParamScalar> elastic;

  /**
   * Material state for small strain mechanical simulation.
   */
  template <int dim>
  struct SmallStrainState {
    /**
     * The strain tensor assuming small strains and rotations
     * $\BoldSymbol{\varepsilon$}$.
     */
    typename Config::Strain<dim> strain;
    /**
     * The stress tensor $\BoldSymbol{\sigma}$.
     */
    typename Config::CauchyStress<dim> stress;
  };

  template <int dim>
  void small_strain_alldim(const SmallStrainState<dim> & /*previous*/,
                           SmallStrainState<dim> &current,
                           constraints::MechAllDim constraints) const {
    Assert(constraints == constraints::MechAllDim::FixedStrain,
           ExcNotImplemented());
    using Scalar = typename Config::StateScalar;
    const auto I = unit_symmetric_tensor<dim, Scalar>();
    current.stress = elastic.lambda * trace(current.strain) * I +
                     Scalar{2} * elastic.mu * current.strain;
  }
};
} // namespace constitutive
