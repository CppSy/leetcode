class Solution {
public:
    int minFlips(int a, int b, int c) {
        string a1, b1, c1;
        bitset<32> binary(a);
        a1 = binary.to_string();
        if (true) {
            bitset<32> bitsetRepresentation(b);
            b1 = bitsetRepresentation.to_string();
        }
        if (true) {
            bitset<32> bitsetRepresentation(c);
            c1 = bitsetRepresentation.to_string();
        }
        int changes = 0;
        for (int i = 31; i >= 0; i--) {
            if (c1[i] == '1') {
                if (a1[i] != '1' && b1[i] != '1')  changes++;
            } else {
                    if(a1[i]=='1') changes++;
                    if(b1[i]=='1') changes++;
            }
        }
        return changes;
    }
};