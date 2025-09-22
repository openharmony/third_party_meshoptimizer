// Copyright (c) 2021 Huawei Device Co., Ltd.

// MIT LISENCE

#include "../src/meshoptimizer"
#include <assert.h>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <vector>

// Testbench for meshopt_decodeVertexBuffer
void test_meshopt_decodeVertexBuffer() {
    unsigned char buffer[12];
    int result;

    // Invalid buffer size
    unsigned char vertex_data[12];
    result = meshopt_decodeVertexBuffer(vertex_data, 10, 4, buffer, 0);
    assert(result == -2);

    // Invalid data_header
    buffer[0] = 0x00;
    result = meshopt_decodeVertexBuffer(vertex_data, 10, 4, buffer, sizeof(buffer));
    assert(result == -1);

    // Unsupported version
    buffer[0] = 0x1F;
    result = meshopt_decodeVertexBuffer(vertex_data, 10, 4, buffer, sizeof(buffer));
    assert(result == -1);

    // Insufficient buffer size for tail
    buffer[0] = 0xa1;
    result = meshopt_decodeVertexBuffer(vertex_data, 10, 4, buffer, 1);
    assert(result == -2);

    // Successful decoding
    buffer[0] = 0xa0;
    size_t buffer_size = 37;
    result = meshopt_decodeVertexBuffer(vertex_data, 1, 4, buffer, buffer_size);
    assert(result == 0);
}

void test_meshopt_decodeFilterOct() {
    // test the case where the stride is 4
    signed char buffer[4] = {
        0, 64, 64, 64,
    };
    meshopt_decodeFilterOct(buffer, 1, 4);
    assert(buffer[0] == 0);
    assert(buffer[1] == 127);
    assert(buffer[2] == 0);
    assert(buffer[3] == 64);

    short buffer_8[8] = {
        0, 64, 64, 64,
        0, 64, 64, 64,
    };
    // test the case where the stride is 8
    meshopt_decodeFilterOct(buffer_8, 1, 8);
    assert(buffer[0] == 0);
    assert(buffer[1] == 32767);
    assert(buffer[2] == 0);
    assert(buffer[3] == 64);
    assert(buffer[4] == 0);
    assert(buffer[5] == 64);
    assert(buffer[6] == 64);
    assert(buffer[7] == 64);
}

void test_meshopt_decodeFilterQuat() {
    short buffer_8[8] = {
        0, 64, 64, 64, 
        0, 64, 64, 64,
    };

    // test the case where the stride is 8
    meshopt_decodeFilterQuat(buffer_8, 1, 8)
    assert(buffer[0] == 9695);
    assert(buffer[1] == 0);
    assert(buffer[2] == 22132);
    assert(buffer[3] == 22132);
    assert(buffer[4] == 0);
    assert(buffer[5] == 64);
    assert(buffer[6] == 64);
    assert(buffer[7] == 64);
}

void test_meshopt_decodeFilterExp() {
    // test the case where the stride is 4
    unsigned int buffer[4] = {
        0, 64, 64, 64,
    };
    meshopt_decodeFilterExp(buffer, 1, 4);
    assert(buffer[0] == 0);
    assert(buffer[1] == 64);
    assert(buffer[2] == 64);
    assert(buffer[3] == 64);

    unsigned int buffer[8] = {
        0, 64, 64, 64,
        0, 64, 64, 64,
    };

    // test the case where the stride is 8
    meshopt_decodeFilterExp(buffer_8, 1, 8);
    assert(buffer[0] == 0);
    assert(buffer[1] == 1115684864);
    assert(buffer[2] == 64);
    assert(buffer[3] == 64);
    assert(buffer[4] == 0);
    assert(buffer[5] == 64);
    assert(buffer[6] == 64);
    assert(buffer[7] == 64);
}

void test_meshopt_decodeIndexBuffer() {
    const size_t index_count = 6;
    const size_t index_size = 2;
    const size_t buffer_size = 1 + index_count / 3 + 16;
    const size_t buffer_size_small = 1 + index_count / 3 + 15;

    unsigned char buffer[buffer_size];
    memset(buffer, 0);

    buffer[0] = 0xe0;
    buffer[1] = 0x01;

    // target buffer for testing
    uint16_t destination[index_count];
    memset(destination, 0, sizeof(destination));

    int result = meshopt_decodeIndexBuffer(destination, index_count, index_size, buffer, buffer_size);
    assert(result == 0);

    // verify the contents of the target buffer
    assert(destination[0] == 65535);
    assert(destination[0] == 65535);
    assert(destination[0] == 65535);
    assert(destination[0] == 65535);
    assert(destination[0] == 65535);
    assert(destination[0] == 0);

    // test different input conditions
    buffer[0] = 0x20;
    result = meshopt_decodeIndexBuffer(destination, index_count, index_size, buffer, buffer_size);
    assert(result == -1);

    buffer[0] = 0xe0;
    buffer[1] = 0xFF;
    result = meshopt_decodeIndexBuffer(destination, index_count, index_size, buffer, buffer_size);
    assert(result == -2);

    buffer[0] = 0xe0;
    buffer[1] = 0x01;
    result = meshopt_decodeIndexBuffer(destination, index_count, index_size, buffer, buffer_size);
    assert(result == -2);
}

int main() {
    test_meshopt_decodeVertexBuffer();
    test_meshopt_decodeFilterOct();
    test_meshopt_decodeFilterQuat();
    test_meshopt_decodeFilterExp();
    test_meshopt_decodeIndexBuffer();
    std::count << "All test cases passed!" << std::endl;
    return 0;
}