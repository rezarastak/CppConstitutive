#pragma once

#include "constitutive/mech/elastic.h"
#include <deal.II/base/symmetric_tensor.h>

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
     * \f$\boldsymbol{\varepsilon}\f$.
     */
    typename Config::template Strain<dim> strain;
    /**
     * The stress tensor \f$\boldsymbol{\sigma}\f$.
     */
    typename Config::template CauchyStress<dim> stress;
  };

  /**
   * Compute the stress values from current state of strain.
   */
  template <int dim>
  void small_strain_update(const SmallStrainState<dim> & /*previous*/,
                           SmallStrainState<dim> &current) const {
    using Scalar = typename Config::StressScalar;
    const auto I = dealii::unit_symmetric_tensor<dim, Scalar>();
    current.stress = elastic.get_lambda() * trace(current.strain) * I +
                     Scalar{2} * elastic.get_mu() * current.strain;
  }
};
} // namespace constitutive
