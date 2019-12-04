#pragma once

namespace constitutive {
/**
 * Linear Elastic material.
 */
template <typename number> struct LinearElastic {
  /**
   * Material states that should be stored and at each material point.
   */
  struct State {
    /**
     * Material state for small strain mechanical simulation.
     */
    template <int dim> struct SmallStrain {
      /**
       * The strain tensor assuming small strains and rotations
       * $\BoldSymbol{\varepsilon$}$.
       */
      Tensor<2, dim> strain;
      /**
       * The stress tensor $\BoldSymbol{\sigma}$.
       */
      Tensor<2, dim> stress;
    };
  };

  /**
   * Elastic parameters describing the material.
   */
  ElasticParams elastic;
};
} // namespace constitutive
