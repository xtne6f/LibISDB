cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_language(CXX)
if(MINGW)
  add_subdirectory(Windows)
endif(MINGW)

project(LibISDB CXX)

add_library(LibISDB STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/ARIBString.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/ARIBTime.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/BitstreamReader.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/DataBuffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/DataStorage.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/DataStorageManager.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/DataStreamer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/DateTime.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/Debug.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/ErrorHandler.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/FileStreamGeneric.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/FileStreamGenericC.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/FileStreamPOSIX.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/JISKanjiMap.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/Logger.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/ObjectBase.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/SIMD.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/StandardStream.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/StreamBuffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/StreamBufferDataStreamer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/StreamingThread.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Base/StreamWriter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Engine/FilterGraph.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Engine/StreamSourceEngine.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Engine/TSEngine.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/EPG/EPGDatabase.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/EPG/EPGDataFile.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/EPG/EventInfo.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/AnalyzerFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/AsyncStreamingFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/CaptionFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/EPGDatabaseFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/FilterBase.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/GrabberFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/LogoDownloaderFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/RecorderFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/ServiceSelectorFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/SourceFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/StreamBufferFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/StreamSourceFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/TeeFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/TSPacketCounterFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Filters/TSPacketParserFilter.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MediaParsers/ADTSParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MediaParsers/H264Parser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MediaParsers/H265Parser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MediaParsers/MPEG2VideoParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/MediaParsers/MPEGVideoParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/CaptionParser.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/DescriptorBase.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/DescriptorBlock.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/Descriptors.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/OneSegPATGenerator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/PESPacket.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/PIDMap.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/PSISection.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/PSITable.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/StreamSelector.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/Tables.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/TSDownload.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/TSInformation.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/TS/TSPacket.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/AlignedAlloc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/BitRateCalculator.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/ConditionVariable.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/CRC.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/Lock.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/MD5.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/Thread.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/Utilities/Utilities.cpp
)

if(NOT WIN32)
  set_target_properties(LibISDB PROPERTIES PREFIX "")
  set_target_properties(LibISDB PROPERTIES OUTPUT_NAME "libisdb")
endif(NOT WIN32)

if(MINGW)
  target_sources(LibISDB PRIVATE Base/FileStreamWindows.cpp)
  target_compile_options(LibISDB PRIVATE -msse -msse2)
  target_compile_definitions(LibISDB PRIVATE _FILE_OFFSET_BITS=64 _UNICODE UNICODE)
  set_target_properties(LibISDB PROPERTIES SUFFIX ".lib")
endif(MINGW)

install(TARGETS LibISDB ARCHIVE DESTINATION lib)

add_custom_target(LibISDBVersionHash COMMAND ./versionhashgen.sh WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
if(GEN_LIBISDB_VERSION_HASH)
  add_dependencies(LibISDB LibISDBVersionHash)
endif()
