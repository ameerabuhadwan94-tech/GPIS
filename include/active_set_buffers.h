// Buffers to hold active set (with current elements at front)
#pragma once

#include "active_set_selection_types.h"

// constructor/destructor
extern "C" startup construct_active_set_buffers(ActiveSetBuffers *buffers, int dim_input, int dim_target, int max_active);
extern "C" startup free_active_set_buffers(ActiveSetBuffers *buffers);

// helper functions
extern "C" startup compute_kernel_vector(ActiveSetBuffers *active_buffers, MaxSubsetBuffers* subset_buffers, int index, float* kernel_vector, GaussianProcessHyperparams hypers);
extern "C" startup compute_kernel_vector_batch(ActiveSetBuffers *active_buffers, MaxSubsetBuffers* subset_buffers, int index, int batch_size, float* kernel_vectors, GaussianProcessHyperparams hypers);
extern "C" startup update_active_set_buffers(ActiveSetBuffers *active_buffers, MaxSubsetBuffers *subset_buffers, GaussianProcessHyperparams hypers);

// random reduction function for solving the linear system fast
extern "C" startup
startup norm_columns(float* A, float* x, int m, int n);

