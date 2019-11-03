def hex_xor(hexS1, hexS2):
    """Takes two equal-length hex encoded buffers and produces their XOR combination."""
    S1 = int(hexdata1, 16)
    S2 = int(hexdata2, 16)
    xor = S1 ^ S2
    return hex(xor)[2:]


def main():
    # Check that the method works properly
    assert hex_xor("1c0111001f010100061a024b53535009181c", "686974207468652062756c6c277320657965") ==\
           "746865206b696420646f6e277420706c6179"


if __name__ == '__main__':
    main()
