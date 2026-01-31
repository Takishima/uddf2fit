#!/usr/bin/env python3
"""Decode and display all messages from a Garmin FIT file.

This script uses the Garmin FIT SDK to decode a FIT file and print all
messages in the order they appear, showing message types and field values.
"""

import sys
import os

# Add the src directory to the path so we can import the SDK
sys.path.insert(0, os.path.join(os.path.dirname(__file__), '..', 'src'))

from garmin_fit_sdk_py import Decoder, Stream, Profile


def format_value(value):
    """Format a value for display."""
    if isinstance(value, bytes):
        return f"<bytes len={len(value)}>"
    elif isinstance(value, list):
        if len(value) > 10:
            return f"[{', '.join(str(v) for v in value[:10])}... ({len(value)} items)]"
        return str(value)
    return str(value)


def decode_fit_file(filepath: str, verbose: bool = True):
    """Decode a FIT file and print all messages."""
    
    print(f"Decoding FIT file: {filepath}")
    print("=" * 80)
    
    # Create fresh stream 
    stream = Stream.from_file(filepath)
    decoder = Decoder(stream)
    
    print(f"Stream length: {stream.get_length()}")
    
    if not decoder.is_fit():
        print("ERROR: Not a valid FIT file")
        return
    
    print("is_fit: PASSED")
    
    # Decode all messages
    messages, errors = decoder.read()
    
    if errors:
        print(f"\nDecoding errors: {errors}")
    
    print(f"\nMessages dictionary keys: {list(messages.keys())}")
    
    # Count total messages
    total = sum(len(v) for v in messages.values())
    print(f"Total messages decoded: {total}")
    
    print("\n" + "=" * 80)
    print("MESSAGE TYPE SUMMARY")
    print("=" * 80)
    
    # Print message type summary
    for mesg_name, mesg_list in sorted(messages.items(), key=lambda x: -len(x[1])):
        print(f"  {mesg_name}: {len(mesg_list)}")
    
    print("\n" + "=" * 80)
    print("ALL MESSAGES BY TYPE")
    print("=" * 80)
    
    # Print all messages grouped by type
    for mesg_name, mesg_list in messages.items():
        print(f"\n{'='*80}")
        print(f"MESSAGE TYPE: {mesg_name} ({len(mesg_list)} messages)")
        print("=" * 80)
        
        for idx, msg in enumerate(mesg_list):
            print(f"\n  [{idx}] {mesg_name}")
            print("  " + "-" * 58)
            
            # Sort by string representation of field name
            for field_name, value in sorted(msg.items(), key=lambda x: str(x[0])):
                formatted = format_value(value)
                print(f"      {field_name}: {formatted}")
    
    print("\n" + "=" * 80)
    print("DECODE COMPLETE")
    print("=" * 80)
    
    return messages, errors


if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python decode_fit.py <fit_file>")
        sys.exit(1)
    
    filepath = sys.argv[1]
    if not os.path.exists(filepath):
        print(f"ERROR: File not found: {filepath}")
        sys.exit(1)
    
    decode_fit_file(filepath)
