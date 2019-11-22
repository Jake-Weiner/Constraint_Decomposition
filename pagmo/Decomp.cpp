#include "Decomp.hpp"
#include <cmath>
#include <initializer_list>
#include <stdexcept>
#include <string>
#include <utility>

#include <pagmo/exceptions.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/problems/schwefel.hpp>
#include <pagmo/s11n.hpp>
#include <pagmo/types.hpp>

namespace pagmo {


double sum(const vector_double& input)
{

    double sum = 0;
    for (auto& var_val : input) {
        sum += var_val;
    }
    return sum;
}

Decomp::Decomp(int dim, const Hypergraph& hypergraph) : m_dim(dim), HG(hypergraph)
{
    if (dim < 1u) {
        pagmo_throw(std::invalid_argument,
                    "Decomp Function must have minimum 1 dimension, " + std::to_string(dim) + " requested");
    }
}

vector_double Decomp::fitness(const vector_double& dv) const
{

    vector_double objective;
    // updateHG(dv);
    HG.partitionWithRelaxation(dv);
    double largest_partition = double(HG.getLargestPartition(dv, false));
    double sum_x = sum(dv);
    objective.push_back(largest_partition);
    objective.push_back(sum_x);
    return objective;
}

std::pair<vector_double, vector_double> Decomp::get_bounds() const
{
    vector_double lb(m_dim, 0);
    vector_double ub(m_dim, 1);
    return {lb, ub};
}

vector_double::size_type Decomp::get_nix() const
{
    return size_t(m_dim);
}

template <typename Archive>
void Decomp::serialize(Archive& ar, unsigned)
{
    ar& m_dim;
}

} // namespace pagmo



