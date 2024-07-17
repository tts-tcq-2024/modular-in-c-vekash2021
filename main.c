#include <stdio.h>
#include <assert.h> 
#include "numconvtopaircolour.h"
#include "pair2numberconversion.h"
#include "pairscolourdata.h"


void testNumberTocolourPair(int pairNumber,
    enum MajorColor expectedMajor,
    enum MinorColor expectedMinor)
{
    ColorPair colorPair = GetNumberFrompairColor(pairNumber);
    char colorPairNames[MAX_COLORPAIR_NAME_CHARS];
    PrintColorPairToString(&colorPair, colorPairNames);
    printf("Got pair %s\n", colorPairNames);
    assert(colorPair.majorColor == expectedMajor);
    assert(colorPair.minorColor == expectedMinor);
}

void testPairToNumber(
    enum MajorColor major,
    enum MinorColor minor,
    int expectedPairNumber)
{
    ColorPair colorPair;
    colorPair.majorColor = major;
    colorPair.minorColor = minor;
    int pairNumber = GetNumberFrompairColor(&colorPair);
    printf("Got pair number %d\n", pairNumber);
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberTocolourPair(4, WHITE, BROWN);
    testNumberTocolourPair(5, WHITE, SLATE);

    testNumberTocolourPair(BLACK, ORANGE, 12);
    testNumberTocolourPair(VIOLET, SLATE, 25);

    return 0;
}
