cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(BaseClasses CXX)

add_library(${PROJECT_NAME} STATIC
  ../../Thirdparty/BaseClasses/amextra.cpp
  ../../Thirdparty/BaseClasses/amfilter.cpp
  ../../Thirdparty/BaseClasses/amvideo.cpp
  ../../Thirdparty/BaseClasses/arithutil.cpp
  ../../Thirdparty/BaseClasses/combase.cpp
  ../../Thirdparty/BaseClasses/cprop.cpp
  ../../Thirdparty/BaseClasses/ctlutil.cpp
  ../../Thirdparty/BaseClasses/ddmm.cpp
  ../../Thirdparty/BaseClasses/dllentry.cpp
  ../../Thirdparty/BaseClasses/dllsetup.cpp
  ../../Thirdparty/BaseClasses/mtype.cpp
  ../../Thirdparty/BaseClasses/outputq.cpp
  ../../Thirdparty/BaseClasses/perflog.cpp
  ../../Thirdparty/BaseClasses/pstream.cpp
  ../../Thirdparty/BaseClasses/pullpin.cpp
  ../../Thirdparty/BaseClasses/refclock.cpp
  ../../Thirdparty/BaseClasses/renbase.cpp
  ../../Thirdparty/BaseClasses/schedule.cpp
  ../../Thirdparty/BaseClasses/seekpt.cpp
  ../../Thirdparty/BaseClasses/source.cpp
  ../../Thirdparty/BaseClasses/strmctl.cpp
  ../../Thirdparty/BaseClasses/sysclock.cpp
  ../../Thirdparty/BaseClasses/transfrm.cpp
  ../../Thirdparty/BaseClasses/transip.cpp
  ../../Thirdparty/BaseClasses/videoctl.cpp
  ../../Thirdparty/BaseClasses/vtrans.cpp
  ../../Thirdparty/BaseClasses/winctrl.cpp
  ../../Thirdparty/BaseClasses/winutil.cpp
  ../../Thirdparty/BaseClasses/wxdebug.cpp
  ../../Thirdparty/BaseClasses/wxlist.cpp
  ../../Thirdparty/BaseClasses/wxutil.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -msse -msse2 -fpermissive)
target_compile_definitions(${PROJECT_NAME} PRIVATE _UNICODE UNICODE)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Thirdparty/BaseClasses)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".lib")

project(liba52 C)

add_library(${PROJECT_NAME} STATIC
  ../../Thirdparty/a52dec/liba52/bitstream.c
  ../../Thirdparty/a52dec/liba52/bit_allocate.c
  ../../Thirdparty/a52dec/liba52/downmix.c
  ../../Thirdparty/a52dec/liba52/imdct.c
  ../../Thirdparty/a52dec/liba52/parse.c
)

target_compile_options(${PROJECT_NAME} PRIVATE -msse -msse2)
target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Thirdparty/a52dec/include ../../Thirdparty/a52dec/vc++)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".lib")

project(libfaad C)

add_library(${PROJECT_NAME} STATIC
  ../../Thirdparty/faad2/libfaad/bits.c
  ../../Thirdparty/faad2/libfaad/cfft.c
  ../../Thirdparty/faad2/libfaad/common.c
  ../../Thirdparty/faad2/libfaad/decoder.c
  ../../Thirdparty/faad2/libfaad/drc.c
  ../../Thirdparty/faad2/libfaad/drm_dec.c
  ../../Thirdparty/faad2/libfaad/error.c
  ../../Thirdparty/faad2/libfaad/filtbank.c
  ../../Thirdparty/faad2/libfaad/hcr.c
  ../../Thirdparty/faad2/libfaad/huffman.c
  ../../Thirdparty/faad2/libfaad/ic_predict.c
  ../../Thirdparty/faad2/libfaad/is.c
  ../../Thirdparty/faad2/libfaad/lt_predict.c
  ../../Thirdparty/faad2/libfaad/mdct.c
  ../../Thirdparty/faad2/libfaad/mp4.c
  ../../Thirdparty/faad2/libfaad/ms.c
  ../../Thirdparty/faad2/libfaad/output.c
  ../../Thirdparty/faad2/libfaad/pns.c
  ../../Thirdparty/faad2/libfaad/ps_dec.c
  ../../Thirdparty/faad2/libfaad/ps_syntax.c
  ../../Thirdparty/faad2/libfaad/pulse.c
  ../../Thirdparty/faad2/libfaad/rvlc.c
  ../../Thirdparty/faad2/libfaad/sbr_dct.c
  ../../Thirdparty/faad2/libfaad/sbr_dec.c
  ../../Thirdparty/faad2/libfaad/sbr_e_nf.c
  ../../Thirdparty/faad2/libfaad/sbr_fbt.c
  ../../Thirdparty/faad2/libfaad/sbr_hfadj.c
  ../../Thirdparty/faad2/libfaad/sbr_hfgen.c
  ../../Thirdparty/faad2/libfaad/sbr_huff.c
  ../../Thirdparty/faad2/libfaad/sbr_qmf.c
  ../../Thirdparty/faad2/libfaad/sbr_syntax.c
  ../../Thirdparty/faad2/libfaad/sbr_tf_grid.c
  ../../Thirdparty/faad2/libfaad/specrec.c
  ../../Thirdparty/faad2/libfaad/ssr.c
  ../../Thirdparty/faad2/libfaad/ssr_fb.c
  ../../Thirdparty/faad2/libfaad/ssr_ipqf.c
  ../../Thirdparty/faad2/libfaad/syntax.c
  ../../Thirdparty/faad2/libfaad/tns.c
)

target_compile_options(${PROJECT_NAME} PRIVATE -msse -msse2)
target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Thirdparty/faad2/libfaad ../../Thirdparty/faad2/include)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".lib")

project(libmad C)

add_library(${PROJECT_NAME} STATIC
  ../../Thirdparty/libmad/bit.c
  ../../Thirdparty/libmad/decoder.c
  ../../Thirdparty/libmad/fixed.c
  ../../Thirdparty/libmad/frame.c
  ../../Thirdparty/libmad/huffman.c
  ../../Thirdparty/libmad/layer12.c
  ../../Thirdparty/libmad/layer3.c
  ../../Thirdparty/libmad/stream.c
  ../../Thirdparty/libmad/synth.c
  ../../Thirdparty/libmad/timer.c
  ../../Thirdparty/libmad/version.c
)

target_compile_options(${PROJECT_NAME} PRIVATE -msse -msse2)
target_compile_definitions(${PROJECT_NAME} PRIVATE HAVE_CONFIG_H FPM_INTEL ASO_ZEROCHECK)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".lib")

project(LibISDBWindows CXX)

add_library(${PROJECT_NAME} STATIC
  Base/BonDriver.cpp
  Base/EDCBPluginWriter.cpp
  Filters/BonDriverSourceFilter.cpp
  Viewer/DirectShow/AudioDecoders/AACDecoder.cpp
  Viewer/DirectShow/AudioDecoders/AC3Decoder.cpp
  Viewer/DirectShow/AudioDecoders/AudioDecoder.cpp
  Viewer/DirectShow/AudioDecoders/AudioDecoderFilter.cpp
  Viewer/DirectShow/AudioDecoders/MPEGAudioDecoder.cpp
  Viewer/DirectShow/DirectShowFilterGraph.cpp
  Viewer/DirectShow/DirectShowUtilities.cpp
  Viewer/DirectShow/ImageMixers/ImageMixer.cpp
  Viewer/DirectShow/ImageMixers/ImageMixer_EVR.cpp
  Viewer/DirectShow/ImageMixers/ImageMixer_VMR.cpp
  Viewer/DirectShow/ImageMixers/ImageMixer_VMR7.cpp
  Viewer/DirectShow/ImageMixers/ImageMixer_VMR9.cpp
  Viewer/DirectShow/KnownDecoderManager.cpp
  Viewer/DirectShow/SourceFilter/TSSourceFilter.cpp
  Viewer/DirectShow/SourceFilter/TSSourcePin.cpp
  Viewer/DirectShow/SourceFilter/TSSourceStream.cpp
  Viewer/DirectShow/VideoParsers/H264ParserFilter.cpp
  Viewer/DirectShow/VideoParsers/H265ParserFilter.cpp
  Viewer/DirectShow/VideoParsers/MPEG2ParserFilter.cpp
  Viewer/DirectShow/VideoParsers/VideoParser.cpp
  Viewer/DirectShow/VideoRenderers/EVRCustomPresenter/EVRHelpers.cpp
  Viewer/DirectShow/VideoRenderers/EVRCustomPresenter/EVRMediaType.cpp
  Viewer/DirectShow/VideoRenderers/EVRCustomPresenter/EVRPresentEngine.cpp
  Viewer/DirectShow/VideoRenderers/EVRCustomPresenter/EVRPresenter.cpp
  Viewer/DirectShow/VideoRenderers/EVRCustomPresenter/EVRScheduler.cpp
  Viewer/DirectShow/VideoRenderers/EVRCustomPresenter/VideoRenderer_EVRCustomPresenter.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer_EVR.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer_madVR.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer_OverlayMixer.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer_VMR7.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer_VMR7Renderless.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer_VMR9.cpp
  Viewer/DirectShow/VideoRenderers/VideoRenderer_VMR9Renderless.cpp
  Viewer/ViewerEngine.cpp
  Viewer/ViewerFilter.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -msse -msse2)
target_compile_definitions(${PROJECT_NAME} PRIVATE _FILE_OFFSET_BITS=64 _UNICODE UNICODE)
target_include_directories(${PROJECT_NAME} PRIVATE ../../Thirdparty/faad2/include ../../Thirdparty/BaseClasses)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".lib")
