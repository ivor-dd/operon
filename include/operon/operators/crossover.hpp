#ifndef CROSSOVER_HPP
#define CROSSOVER_HPP

#include <vector>

#include "core/operator.hpp"

namespace Operon 
{
    class SubtreeCrossover : public CrossoverBase 
    {
        public:
            SubtreeCrossover(double p, size_t d, size_t l) : internalProbability(p), maxDepth(d), maxLength(l) { } 
            std::optional<size_t> SelectRandomBranch(RandomDevice& random, const Tree& tree, double internalProbability, size_t maxBranchDepth, size_t maxBranchLength) const;
            size_t CutRandom(RandomDevice& random, const Tree& tree, double internalProb) const;
            auto operator()(RandomDevice& random, const Tree& lhs, const Tree& rhs) const -> Tree override;

        private:
            double internalProbability;
            long maxDepth;
            long maxLength;
    };
}
#endif
