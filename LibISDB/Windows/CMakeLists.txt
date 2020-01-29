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

project(fdk-aac CXX)

add_library(${PROJECT_NAME} STATIC
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdecoder.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdecoder_lib.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdec_drc.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdec_hcr.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdec_hcrs.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdec_hcr_bit.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdec_pns.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aacdec_tns.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aac_ram.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/aac_rom.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/block.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/channel.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/channelinfo.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/conceal.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/FDK_delay.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/ldfiltbank.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/pulsedata.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/rvlc.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/rvlcbit.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/rvlcconceal.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/stereo.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/usacdec_acelp.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/usacdec_ace_d4t64.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/usacdec_ace_ltp.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/usacdec_fac.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/usacdec_lpc.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/usacdec_lpd.cpp
  ../../Thirdparty/fdk-aac/libAACdec/src/usacdec_rom.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/aacenc.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/aacenc_lib.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/aacenc_pns.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/aacEnc_ram.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/aacEnc_rom.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/aacenc_tns.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/adj_thr.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/bandwidth.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/band_nrg.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/bitenc.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/bit_cnt.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/block_switch.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/channel_map.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/chaosmeasure.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/dyn_bits.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/grp_data.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/intensity.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/line_pe.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/metadata_compressor.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/metadata_main.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/mps_main.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/ms_stereo.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/noisedet.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/pnsparam.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/pre_echo_control.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/psy_configuration.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/psy_main.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/qc_main.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/quantize.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/sf_estim.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/spreading.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/tonality.cpp
  ../../Thirdparty/fdk-aac/libAACenc/src/transform.cpp
  ../../Thirdparty/fdk-aac/libArithCoding/src/ac_arith_coder.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcDec_gainDecoder.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcDec_reader.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcDec_rom.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcDec_selectionProcess.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcDec_tools.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcGainDec_init.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcGainDec_preprocess.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/drcGainDec_process.cpp
  ../../Thirdparty/fdk-aac/libDRCdec/src/FDK_drcDecLib.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/autocorr2nd.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/dct.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_bitbuffer.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_core.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_crc.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_decorrelate.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_hybrid.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_lpc.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_matrixCalloc.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_qmf_domain.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_tools_rom.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/FDK_trigFcts.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/fft.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/fft_rad2.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/fixpoint_math.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/huff_nodes.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/mdct.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/nlc_dec.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/qmf.cpp
  ../../Thirdparty/fdk-aac/libFDK/src/scale.cpp
  ../../Thirdparty/fdk-aac/libMpegTPDec/src/tpdec_adif.cpp
  ../../Thirdparty/fdk-aac/libMpegTPDec/src/tpdec_adts.cpp
  ../../Thirdparty/fdk-aac/libMpegTPDec/src/tpdec_asc.cpp
  ../../Thirdparty/fdk-aac/libMpegTPDec/src/tpdec_drm.cpp
  ../../Thirdparty/fdk-aac/libMpegTPDec/src/tpdec_latm.cpp
  ../../Thirdparty/fdk-aac/libMpegTPDec/src/tpdec_lib.cpp
  ../../Thirdparty/fdk-aac/libMpegTPEnc/src/tpenc_adif.cpp
  ../../Thirdparty/fdk-aac/libMpegTPEnc/src/tpenc_adts.cpp
  ../../Thirdparty/fdk-aac/libMpegTPEnc/src/tpenc_asc.cpp
  ../../Thirdparty/fdk-aac/libMpegTPEnc/src/tpenc_latm.cpp
  ../../Thirdparty/fdk-aac/libMpegTPEnc/src/tpenc_lib.cpp
  ../../Thirdparty/fdk-aac/libPCMutils/src/limiter.cpp
  ../../Thirdparty/fdk-aac/libPCMutils/src/pcmdmx_lib.cpp
  ../../Thirdparty/fdk-aac/libPCMutils/src/pcm_utils.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_bitdec.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_calcM1andM2.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_dec.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_dec_conceal.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_dec_lib.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_process.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_qmf.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_reshapeBBEnv.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_rom.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_smoothing.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_stp.cpp
  ../../Thirdparty/fdk-aac/libSACdec/src/sac_tsd.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_bitstream.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_delay.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_dmx_tdom_enh.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_filter.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_framewindowing.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_huff_tab.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_lib.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_nlc_enc.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_onsetdetect.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_paramextract.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_staticgain.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_tree.cpp
  ../../Thirdparty/fdk-aac/libSACenc/src/sacenc_vectorfunctions.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/env_calc.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/env_dec.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/env_extr.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/hbe.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/HFgen_preFlat.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/huff_dec.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/lpp_tran.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/psbitdec.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/psdec.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/pvc_dec.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/sbrdecoder.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/sbrdec_drc.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/sbrdec_freq_sca.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/sbr_crc.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/sbr_dec.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/sbr_ram.cpp
  ../../Thirdparty/fdk-aac/libSBRdec/src/sbr_rom.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/bit_sbr.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/code_env.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/env_bit.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/env_est.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/fram_gen.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/invf_est.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/mh_det.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/nf_est.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/ps_bitenc.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/ps_encode.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/ps_main.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/resampler.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/sbrenc_freq_sca.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/sbrenc_ram.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/sbrenc_rom.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/sbr_encoder.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/sbr_misc.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/ton_corr.cpp
  ../../Thirdparty/fdk-aac/libSBRenc/src/tran_det.cpp
  ../../Thirdparty/fdk-aac/libSYS/src/genericStds.cpp
  ../../Thirdparty/fdk-aac/libSYS/src/syslib_channelMapDescr.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE -msse -msse2)
target_include_directories(${PROJECT_NAME} PRIVATE
  ../../Thirdparty/fdk-aac/libAACdec/include
  ../../Thirdparty/fdk-aac/libAACenc/include
  ../../Thirdparty/fdk-aac/libArithCoding/include
  ../../Thirdparty/fdk-aac/libDRCdec/include
  ../../Thirdparty/fdk-aac/libFDK/include
  ../../Thirdparty/fdk-aac/libMpegTPDec/include
  ../../Thirdparty/fdk-aac/libMpegTPEnc/include
  ../../Thirdparty/fdk-aac/libPCMutils/include
  ../../Thirdparty/fdk-aac/libSACdec/include
  ../../Thirdparty/fdk-aac/libSACenc/include
  ../../Thirdparty/fdk-aac/libSBRdec/include
  ../../Thirdparty/fdk-aac/libSBRenc/include
  ../../Thirdparty/fdk-aac/libSYS/include
  ../../Thirdparty/fdk-aac/win32
)
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
  Viewer/DirectShow/AudioDecoders/AACDecoder_FAAD2.cpp
  Viewer/DirectShow/AudioDecoders/AACDecoder_FDK.cpp
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
target_include_directories(${PROJECT_NAME} PRIVATE ../../Thirdparty/faad2/include ../../Thirdparty/fdk-aac/libSYS/include ../../Thirdparty/BaseClasses)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".lib")
