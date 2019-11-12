#include <gtest-wrapper.h>

#include <Filters/Butterworth.hpp>

TEST(Butterworth, evenOrder) {
    using namespace std;
    auto butterworth = butter<6>(0.4 * M_PI);
    array<double, 20> signal = {100.0, 10.0,  102.0,  23.0,  51.0,  1.0,  -10.0,
                                -53.0, 100.0, -100.0, 100.0, -10.0, 10.0, 11.0,
                                20.0,  30.0,  123.0,  12.0,  90.0,  10.0};
    array<double, 20> expected = {
        1.0312874762664406,  7.5156113134959055,  24.719492782414466,
        48.96419197331465,   65.94168547692809,   64.64286189231214,
        47.611566793390764,  24.459114479787313,  2.30670651957257,
        -12.501024944555455, -12.471303690929604, 1.1900356191047718,
        16.094778615441065,  22.424208472570697,  19.737752153200365,
        13.049801559138237,  11.18792332879074,   23.200472458577526,
        48.392807471527775,  71.09457974808586};
    transform(signal.begin(), signal.end(), signal.begin(), butterworth);
    for (size_t i = 0; i < signal.size(); ++i)
        EXPECT_FLOAT_EQ(signal[i], expected[i]) << i;
}

TEST(Butterworth, oddOrder) {
    using namespace std;
    auto butterworth = butter<7>(0.4 * M_PI);
    array<double, 20> signal = {100.0, 10.0,  102.0,  23.0,  51.0,  1.0,  -10.0,
                                -53.0, 100.0, -100.0, 100.0, -10.0, 10.0, 11.0,
                                20.0,  30.0,  123.0,  12.0,  90.0,  10.0};
    array<double, 20> expected = {
        0.48421152393466566, 4.110607277163259,   15.90100516824798,
        37.248782223463,     59.24082887044678,   67.86896938263345,
        57.57371920434696,   35.23288182688867,   11.224568208632098,
        -7.1755802352153415, -14.039847708901476, -6.495413585543419,
        9.106139776920436,   20.900070928261584,  22.518746478860155,
        16.559558467508843,  11.188799404184095,  16.064770949249294,
        35.58427055190113,   61.332940440798545};
    transform(signal.begin(), signal.end(), signal.begin(), butterworth);
    for (size_t i = 0; i < signal.size(); ++i)
        EXPECT_FLOAT_EQ(signal[i], expected[i]) << i;
}