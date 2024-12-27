#!/usr/bin/env python3

import os
import argparse

def binary_to_c_array(binary_file, output_file, array_name):
    """
    Converts a binary file to a uint8_t C array.

    :param binary_file: Path to the binary file.
    :param output_file: Path to the output C file.
    :param array_name: Name of the C array.
    """
    if not os.path.isfile(binary_file):
        print(f"Error: The file '{binary_file}' does not exist.")
        return

    try:
        with open(binary_file, 'rb') as bin_file:
            data = bin_file.read()

        with open(output_file, 'w') as c_file:
            c_file.write(f"#include <stdint.h>\n\n")
            c_file.write(f"const uint8_t {array_name}[] = {{\n")

            # Write the data as hex values, 16 values per line for readability
            for i in range(0, len(data), 16):
                hex_values = ', '.join(f"0x{byte:02X}" for byte in data[i:i+16])
                c_file.write(f"    {hex_values},\n")

            c_file.write(f"}};\n\n")
            c_file.write(f"const size_t {array_name}_len = {len(data)};\n")

        print(f"Successfully created '{output_file}' containing the C array.")

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Convert a binary file to a uint8_t C array.")
    parser.add_argument("binary_file", help="Path to the binary file.")
    parser.add_argument("output_file", help="Path to the output C file.")
    parser.add_argument("array_name", help="Name of the C array.")

    args = parser.parse_args()

    if not os.path.isfile(args.binary_file):
        parser.error(f"The binary file '{args.binary_file}' does not exist.")

    binary_to_c_array(args.binary_file, args.output_file, args.array_name)
