set(ARTIC_MAIN_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/core/bbox.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/color.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/cpu_common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/gpu_common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/matrix.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/print.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/random.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/sort.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/stats.art
    ${CMAKE_CURRENT_SOURCE_DIR}/core/vector.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/aov.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/accumulator.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/bsdf.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/buffer.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/buffer_cpu.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/buffer_gpu.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/camera.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/data.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/device.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/driver.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/entity.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/image.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/light.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/mapping_cpu.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/mapping_gpu.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/material.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/medium.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/pdf.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/phase.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/pipeline.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/registry.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/scene.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/settings.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/shape.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/streams.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/surface_element.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/technique.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/texture.art
    ${CMAKE_CURRENT_SOURCE_DIR}/render/tonemap.art
    ${CMAKE_CURRENT_SOURCE_DIR}/traversal/bvh.art
    ${CMAKE_CURRENT_SOURCE_DIR}/traversal/intersection.art
    ${CMAKE_CURRENT_SOURCE_DIR}/traversal/mapping_cpu.art
    ${CMAKE_CURRENT_SOURCE_DIR}/traversal/mapping_gpu.art
    ${CMAKE_CURRENT_SOURCE_DIR}/traversal/ray.art
    ${CMAKE_CURRENT_SOURCE_DIR}/traversal/stack.art
)

set(ARTIC_EXTRA_SRC
    ${ARTIC_MAIN_SRC}
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/conductor.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/dielectric.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/diffuse.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/klems.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/map.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/mix.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/phong.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/plastic.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/principled.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/bsdf/tensortree.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/camera/common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/camera/fishlens.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/camera/orthogonal.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/camera/perspective.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light/area.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light/cie.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light/common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light/env.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light/point.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light/spot.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light/sun.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/medium/common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/medium/homogeneous.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/phase/common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/phase/henyeygreenstein.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/phase/uniform.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/technique/aotracer.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/technique/debugtracer.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/technique/pathtracer.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/technique/photonmapper.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/technique/volpathtracer.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/technique/wireframe.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/texture/brick.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/texture/common.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/texture/checkerboard.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/texture/image.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/texture/noise.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/cdf.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/color.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/emitter.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/fresnel.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/interval.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/light_selector.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/math.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/microfacet.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/pixel_sampler.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/sampling.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/shading.art
    ${CMAKE_CURRENT_SOURCE_DIR}/impl/warp.art
)

set(ARTIC_MAIN_SRC ${ARTIC_MAIN_SRC} PARENT_SCOPE)
set(ARTIC_EXTRA_SRC ${ARTIC_EXTRA_SRC} PARENT_SCOPE)

anydsl_runtime_wrap(DISCARD_TMP_OBJS
    NAME "interface"
    FRONTEND "artic"
    FILES ${ARTIC_MAIN_SRC} dummy_main.art
    INTERFACE ${CMAKE_BINARY_DIR}/generated_interface)
add_custom_target(artic_c_interface ALL DEPENDS ${CMAKE_BINARY_DIR}/generated_interface.h)
