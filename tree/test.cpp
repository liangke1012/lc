#include <iostream>
using namespace std;

#define DIRECTION_BITS_OFFSET 0x0
#define OFFSET_BITS_OFFSET 0x1
#define INSTRUMENT_BITS_OFFSET 0x3

#define DIRECTION_BITS_MASK 0x1
#define OFFSET_BITS_MASK 0x3
#define INSTRUMENT_BITS_MASK 0x1FFFFFFF

int get_direction(int& val) {
    return (val >> DIRECTION_BITS_OFFSET) & DIRECTION_BITS_MASK;
}

int get_offset(int& val) {
    return (val >> OFFSET_BITS_OFFSET) & OFFSET_BITS_MASK;
}

int get_instrument(int& val) {
    return (val >> INSTRUMENT_BITS_OFFSET) & INSTRUMENT_BITS_MASK;
}

int set_direction(int& val, int new_direction) {
    val |= (new_direction & DIRECTION_BITS_MASK) << DIRECTION_BITS_OFFSET;
    return val;
}

int set_offset(int& val, int new_offset) {
    val |= (new_offset & OFFSET_BITS_MASK) << OFFSET_BITS_OFFSET;
    return val;
}

int set_insturment(int& val, int new_instrument) {
    val |= (new_instrument & INSTRUMENT_BITS_MASK) << INSTRUMENT_BITS_OFFSET;
    return val;
}


int main() {
    int val, offset, direction, insturment;
    int check_val1, check_val2, check_val3;

    cin >> val;
    cin >> direction;
    cin >> offset;
    cin >> insturment;

    check_val1 = val;
    set_direction(val, direction);

    check_val2 = val;
    set_offset(val, offset);

    check_val3 = val;
    set_insturment(val, insturment);

    cout << check_val1 << endl;
    cout << check_val2 << endl;
    cout << check_val3 << endl;
    cout << val << endl;
    return 0;
}
