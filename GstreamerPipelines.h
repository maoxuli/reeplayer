#pragma once

#include <sstream>

#define LINK			" ! "
#define NEW_LINKAGE		" "
#define PAD				"."

#define APPSINK_NAME	"appsink_name"

static std::string CreateRtspSinkPipeline(const std::string& url)
{
    std::stringstream pipelineString;

    pipelineString
        << "rtspsrc location=" << url
        << LINK
        << "decodebin"
        << LINK
        << "videoconvert"
        << LINK
        << "video/x-raw,format=(string)RGB"
        << LINK
        << "appsink drop=true max-buffers=1 max-lateness=100000000 sync=false async=false name=" << APPSINK_NAME;

    return pipelineString.str();
}
