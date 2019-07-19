#ifndef AWS_HTTP_H1_STREAM_H
#define AWS_HTTP_H1_STREAM_H
/*
 * Copyright 2010-2018 Amazon.com, Inc. or its affiliates. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License").
 * You may not use this file except in compliance with the License.
 * A copy of the License is located at
 *
 *  http://aws.amazon.com/apache2.0
 *
 * or in the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

#include <aws/http/private/h1_encoder.h>
#include <aws/http/private/http_impl.h>
#include <aws/http/private/request_response_impl.h>

enum aws_h1_stream_type {
    AWS_H1_STREAM_TYPE_OUTGOING_REQUEST,
    AWS_H1_STREAM_TYPE_INCOMING_REQUEST,
};

struct aws_h1_stream {
    struct aws_http_stream base;

    enum aws_h1_stream_type type;
    struct aws_linked_list_node node;

    /* Message (derived from outgoing request or response) to be submitted to encoder */
    struct aws_h1_encoder_message encoder_message;

    bool is_outgoing_message_done;

    bool is_incoming_message_done;
    bool is_incoming_head_done;

    /* Buffer for incoming data that needs to stick around. */
    struct aws_byte_buf incoming_storage_buf;
};

AWS_EXTERN_C_BEGIN

AWS_HTTP_API
struct aws_h1_stream *aws_h1_stream_new_request(const struct aws_http_request_options *options);

AWS_EXTERN_C_END

#endif /* AWS_HTTP_H1_STREAM_H */
