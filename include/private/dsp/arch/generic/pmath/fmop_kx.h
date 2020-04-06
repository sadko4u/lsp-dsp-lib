/*
 * fmop_kx.h
 *
 *  Created on: 31 мар. 2020 г.
 *      Author: sadko
 */

#ifndef PRIVATE_DSP_ARCH_GENERIC_PMATH_FMOP_KX_H_
#define PRIVATE_DSP_ARCH_GENERIC_PMATH_FMOP_KX_H_

#ifndef PRIVATE_DSP_ARCH_GENERIC_IMPL
    #error "This header should not be included directly"
#endif /* PRIVATE_DSP_ARCH_GENERIC_IMPL */

namespace lsp
{
    namespace generic
    {
        void fmadd_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] += src[i] * k;
        }

        void fmsub_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] -= src[i] * k;
        }

        void fmrsub_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = src[i] * k - dst[i];
        }

        void fmmul_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] *= src[i] * k;
        }

        void fmdiv_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] /= src[i] * k;
        }

        void fmrdiv_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = (src[i] * k) / dst[i];
        }

        void fmmod_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
            {
                float v     = dst[i];
                float d     = src[i] * k;
                int32_t r   = v / d;
                dst[i]      = v - d * r;
            }
        }

        void fmrmod_k3(float *dst, const float *src, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
            {
                float v     = src[i] * k;
                float d     = dst[i];
                int32_t r   = v / d;
                dst[i]      = v - d * r;
            }
        }

        void fmadd_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = src1[i] + src2[i] * k;
        }

        void fmsub_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = src1[i] - src2[i] * k;
        }

        void fmrsub_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = src2[i] * k - src1[i];
        }

        void fmmul_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = src1[i] * src2[i] * k;
        }

        void fmdiv_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = src1[i] / (src2[i] * k);
        }

        void fmrdiv_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
                dst[i] = (src2[i] * k) / src1[i];
        }

        void fmmod_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
            {
                float v     = src1[i];
                float d     = src2[i] * k;
                int32_t r   = v / d;
                dst[i]      = v - d * r;
            }
        }

        void fmrmod_k4(float *dst, const float *src1, const float *src2, float k, size_t count)
        {
            for (size_t i=0; i<count; ++i)
            {
                float v     = src2[i] * k;
                float d     = src1[i];
                int32_t r   = v / d;
                dst[i]      = v - d * r;
            }
        }
    }
}

#endif /* PRIVATE_DSP_ARCH_GENERIC_PMATH_FMOP_KX_H_ */
