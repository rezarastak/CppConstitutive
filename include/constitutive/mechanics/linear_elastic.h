#pragma once

#include <constitutive/mechanics/elastic.h>

namespace constitutive {
/**
 * Linear Elastic material.
 */
template <typename number>
struct LinearElastic {
  /**
   * Elastic parameters describing the material.
   */
  ElasticParams elastic;

  /**
   * Material states that should be stored and at each material point.
   */
  struct State {
    /**
     * Material state for small strain mechanical simulation.
     */
    template <int dim>
    struct SmallStrain {
      /**
       * The strain tensor assuming small strains and rotations
       * $\BoldSymbol{\varepsilon$}$.
       */
      SymmetricTensor<2, dim> strain;
      /**
       * The stress tensor $\BoldSymbol{\sigma}$.
       */
      SymmetricTensor<2, dim> stress;
    };
  };

  template <int dim>
  void small_strain_alldim(const State::SmallStrain<dim> &previous,
                           State::SmallStrain<dim> &next) const;
};
} // namespace constitutive
