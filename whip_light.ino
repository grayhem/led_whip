#include <FastLED.h>

FASTLED_USING_NAMESPACE

// 2x 2m 60/m
// this will be a whip to put on the back of a bike.
// 2m is long also

// want to have a gamma correction in this one. power is gonna be tight.
// 240LED @ 0.06A = 14.4A
// @ 0.02A = 4.8

#if defined(FASTLED_VERSION) && (FASTLED_VERSION < 3001000)
#warning "Requires FastLED 3.1 or later; check github for latest code."
#endif


#define LED_PIN    3
#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    120
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120


void setup() {
    delay(3000); // 3 second delay for recovery

    // tell FastLED about the LED strip configuration
    FastLED.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

    // set master brightness control
    FastLED.setBrightness(BRIGHTNESS);
}

DEFINE_GRADIENT_PALETTE( Sunset_Real_gp ) {
    0, 120,  0,  0,
   22, 179, 22,  0,
   51, 255,104,  0,
   85, 167, 22, 18,
  135, 100,  0,103,
  198,  16,  0,130,
  255,   0,  0,160};

DEFINE_GRADIENT_PALETTE( purplefly_gp ) {
    0,   0,  0,  0,
   63, 239,  0,122,
  191, 252,255, 78,
  255,   0,  0,  0};

DEFINE_GRADIENT_PALETTE( GMT_sealand_gp ) {
    0,  53, 33,255,
   14,  23, 33,255,
   28,  23, 68,255,
   42,  23,115,255,
   56,  23,178,255,
   70,  23,255,255,
   84,  23,255,170,
   99,  23,255,103,
  113,  23,255, 56,
  127,  23,255, 25,
  141,  53,255, 25,
  155, 100,255, 25,
  170, 167,255, 25,
  170, 255,255, 87,
  184, 255,193, 87,
  198, 255,141, 87,
  212, 255, 99, 87,
  226, 255,115,135,
  240, 255,135,182,
  255, 255,156,223};

DEFINE_GRADIENT_PALETTE( bcyr_gp ) {
    0,   0,  0,255,
   84,   0,255,255,
  170, 255,255,  0,
  255, 255,  0,  0};

DEFINE_GRADIENT_PALETTE( GMT_seafloor_gp ) {
    0,  25,  0,109,
   10,  28,  0,119,
   21,  32,  0,127,
   31,  35,  0,140,
   42,  27,  1,145,
   53,  20,  1,151,
   74,  14,  4,156,
   84,   9,  9,164,
   95,   5, 15,170,
  106,   2, 24,176,
  116,   1, 35,182,
  138,   1, 49,188,
  148,   0, 66,197,
  159,   1, 79,203,
  170,   3, 93,210,
  180,  10,109,216,
  191,  24,128,223,
  212,  43,149,230,
  223,  72,173,240,
  233, 112,197,247,
  244, 163,225,255,
  255, 220,248,255};

DEFINE_GRADIENT_PALETTE( mby_gp ) {
    0,   0,  0, 14,
   39,   0,  2, 24,
   78,   0,  7, 25,
  107,   1, 38, 79,
  153,   1, 68,147,
  155,  48,159,242,
  156,  97,195,255,
  156,   0, 30, 10,
  157,   1, 51,  3,
  166, 199,173, 42,
  180,  79, 13,  0,
  192,  44,  2,  1,
  211,  77, 92, 80,
  235, 146,159,149,
  255, 255,255,255};


DEFINE_GRADIENT_PALETTE( jet_gp ) {
    0,   0,  0,123,
   17,   0,  0,255,
   33,   0, 11,255,
   51,   0, 55,255,
   68,   0,135,255,
   84,   0,255,255,
  102,   6,255,255,
  119,  41,255,123,
  135, 120,255, 44,
  153, 255,255,  7,
  170, 255,255,  0,
  186, 255,135,  0,
  204, 255, 55,  0,
  221, 255, 11,  0,
  237, 255,  0,  0,
  255, 120,  0,  0};


DEFINE_GRADIENT_PALETTE( spellbound_gp ) {
    0, 232,235, 40,
   12, 157,248, 46,
   25, 100,246, 51,
   45,  53,250, 33,
   63,  18,237, 53,
   81,  11,211,162,
   94,  18,147,214,
  101,  43,124,237,
  112,  49, 75,247,
  127,  49, 75,247,
  140,  92,107,247,
  150, 120,127,250,
  163, 130,138,252,
  173, 144,131,252,
  186, 148,112,252,
  196, 144, 37,176,
  211, 113, 18, 87,
  221, 163, 33, 53,
  234, 255,101, 78,
  247, 229,235, 46,
  255, 229,235, 46};

DEFINE_GRADIENT_PALETTE( bhw1_06_gp ) {
    0, 184,  1,128,
  160,   1,193,182,
  219, 153,227,190,
  255, 255,255,255};


DEFINE_GRADIENT_PALETTE( bhw1_05_gp ) {
    0,   1,221, 53,
  255,  73,  3,178};

DEFINE_GRADIENT_PALETTE( Primary_3_gp ) {
    0,  16, 82,255,
   63,  91,156,103,
  127, 255,255, 25,
  191, 255,105, 34,
  255, 255, 23, 45};

DEFINE_GRADIENT_PALETTE( Romanian_flag_smooth_gp ) {
    0,   0,  0,255,
   63,  42, 55, 45,
  127, 255,255,  0,
  191, 255, 55,  0,
  255, 255,  0,  0};

DEFINE_GRADIENT_PALETTE( bhw2_39_gp ) {
    0,   2,184,188,
   33,  56, 27,162,
   66,  56, 27,162,
  122, 255,255, 45,
  150, 227, 65,  6,
  201,  67, 13, 27,
  255,  16,  1, 53};


DEFINE_GRADIENT_PALETTE( bhw2_grrrrr_gp ) {
    0, 184, 15,155,
   35,  78, 46,168,
   84,  65,169,230,
  130,   9,127,186,
  163,  77,182,109,
  191, 242,246, 55,
  216, 142,128,103,
  255,  72, 50,168};

DEFINE_GRADIENT_PALETTE( bhw2_turq_gp ) {
    0,   1, 33, 95,
   38,   1,107, 37,
   76,  42,255, 45,
  127, 255,255, 45,
  178,  42,255, 45,
  216,   1,107, 37,
  255,   1, 33, 95};

DEFINE_GRADIENT_PALETTE( bhw3_13_gp ) {
    0,   3,  6, 72,
   38,  12, 50,188,
  109, 217, 35,  1,
  135, 242,175, 12,
  178, 161, 32, 87,
  255,  24,  6,108};


DEFINE_GRADIENT_PALETTE( bhw3_01_gp ) {
    0, 255,146,228,
   25, 152, 43, 65,
   48,  36, 17, 22,
   72,   8, 34, 75,
   81,   1, 58,170,
  104,  42, 49,245,
  124,  15, 15, 95,
  150,   1,  8, 39,
  175,  98, 32, 35,
  204, 123,  9,  2,
  219, 220, 15,  2,
  237, 255, 93,  6,
  255, 244,244,  0};


DEFINE_GRADIENT_PALETTE( bhw4_029_gp ) {
    0,  28,  7, 75,
   43,  73, 22, 74,
   79, 177,146,197,
  122,  21, 72,137,
  165,  15,184, 75,
  255, 224,205,  4};


// List of patterns to cycle through.  Each is defined as a separate function below.
typedef void (*SimplePatternList[])();
SimplePatternList pattern_list = {
    fireworks,
    random_gap,
    continuous_random_walk,
    discontinuous_random_walk,
    // sine_fade_palette
    // rainbow_skip_dark,
    // juggle_skip_light,
    // sine_lond_light
};

typedef CRGBPalette16 PaletteList[];
PaletteList palette_list = {
    bhw4_029_gp,
    Sunset_Real_gp,
    purplefly_gp,
    GMT_sealand_gp,
    bcyr_gp,
    GMT_seafloor_gp,
    mby_gp,
    jet_gp,
    spellbound_gp,
    bhw1_06_gp,
    bhw1_05_gp,
    Primary_3_gp,
    Romanian_flag_smooth_gp,
    bhw2_39_gp,
    bhw2_grrrrr_gp,
    bhw2_turq_gp,
    bhw3_13_gp,
    bhw3_01_gp};

uint8_t pattern_idx = 0;                // Index number of which pattern is current
uint8_t palette_idx = 0;                // fucking guess
uint8_t color_index = 0;                // rotating "base color" used by many of the patterns
uint8_t skip_index = 0;                 // track which LEDs get blacked out
uint8_t light_skip_every = 5;           // one in every _ LEDS get blacked out
uint8_t dark_skip_every = 10;           // one in every _ LEDS don't get blacked out
uint8_t palette_start_index = 0;        // for looping through the color palette specifically
int compact_width = 15;                 // how wide the window of palette
uint8_t random_start = 0;               // for the random walkers
uint8_t random_stop = 10;
int state = 0;                          // need some state for fireworks

// color palette blending courtesy:
    // https://gist.github.com/kriegsman/1f7ccbbfa492a73c015e
uint8_t maxChanges = 24;                // palette blending speed

CRGBPalette16 currentPalette( CRGB::Black);

CRGBPalette16 targetPalette( bhw4_029_gp );


CRGB black = CRGB(0, 0, 0);


#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))





void loop()
{
    // blend this palette to the next
    nblendPaletteTowardPalette( currentPalette, targetPalette, maxChanges);

    // Call the current pattern function once, updating the 'leds' array
    pattern_list[pattern_idx]();


    //palette_start_index = palette_start_index + 1; /* motion speed */

    // send the 'leds' array out to the actual LED strip
    FastLED.show();
    // insert a delay to keep the framerate modest
    FastLED.delay(1000/FRAMES_PER_SECOND);

    // do some periodic updates
    EVERY_N_MILLISECONDS( 20 ) {color_index++;} // slowly cycle the "base color" through the rainbow
    EVERY_N_SECONDS( 10 ) { next_pattern(); } // change patterns periodically
    EVERY_N_SECONDS(17) {next_palette();}   // just make sure it's not divisible by the other one
}


void skip_dark()
{
    // zero out all but a fraction of the LEDS
    for( int i = 0; i < NUM_LEDS; i++) { //9948
        if ((i % dark_skip_every) != skip_index){
            leds[i] = black;
        }
    }
    skip_index = (skip_index + 1) % dark_skip_every;
}


void skip_light()
{
    // zero out a fraction of the LEDS
    for( int i = 0; i < NUM_LEDS; i++) { //9948
        if ((i % light_skip_every) == skip_index){
            leds[i] = black;
        }
    }
    skip_index = (skip_index + 1) % light_skip_every;
}

void next_pattern()
{
    // add one to the current pattern number, and wrap around at the end
    // what a left-handed way to do this
    pattern_idx = (pattern_idx + 1) % ARRAY_SIZE( pattern_list);
}

void next_palette()
{
    // next palette
    // palette_idx = (palette_idx + 1) % ARRAY_SIZE( palette_list);

    //  random palette
    palette_idx = random8() % ARRAY_SIZE(palette_list);

    // update the palette
    targetPalette = palette_list[palette_idx];
}

void rainbow()
{
    // FastLED's built-in rainbow generator
    fill_rainbow( leds, NUM_LEDS, color_index, 7);
}

void rainbow_skip_dark()
{
    rainbow();
    skip_dark();
}



void sine_lond()
{
  // a colored dot sweeping back and forth, with fading trails
    fadeToBlackBy( leds, NUM_LEDS, 20);
    int pos = beatsin16( 13, 0, NUM_LEDS-1 );
    leds[pos] += CHSV(
        color_index,
        255,
        192);
}

void sine_lond_light()
{
    // dim and flickery
    sine_lond();
    skip_light();
}

void juggle() {
    // eight colored dots, weaving in and out of sync with each other
    fadeToBlackBy( leds, NUM_LEDS, 20);
    byte dothue = 0;
    for( int i = 0; i < 8; i++) {
        leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
        dothue += 32;
    }
}

void juggle_skip_light() {
    // eight colored dots, weaving in and out of sync with each other
    juggle();
    skip_light();
}


void sine_fade_palette()
{
    // like sine_lond but we'll slide a palette with compact support around on the strip
    // last arg in fadetoblackby makes it fade faster if it's higher
    fadeToBlackBy( leds, NUM_LEDS, 80);
    int pos = beatsin16( 13, 0, NUM_LEDS-compact_width);
    fill_range_from_palette(pos, pos+compact_width);
}

void fill_range_from_palette(int start_index, int stop_index)
{
    // fill a region of the strip from a palette. if palette_start_index increments too fast and/or
    // the filled region is too large, the region will flicker in an unpleasant way.
    uint8_t brightness = 255;
    for( int i = start_index; i < stop_index; i++) {
        leds[i] = ColorFromPalette(
            currentPalette,
            palette_start_index,
            brightness);
        palette_start_index += 1;
    }
}

void fill_range_from_palette_adaptive(int start_index, int stop_index)
{
    // fill a region of the strip from a palette. if palette_start_index increments too fast and/or
    // the filled region is too large, the region will flicker in an unpleasant way.
    // this one attempts to stretch palettes filling long ranges by reducing incrementing rate of
    // palette_start_index to once every ceil(num_leds_region / `quickness`) pixels.
    // lower values of quickness make colors change more slowly. 10 is good

    int quickness = 10;
    int span = stop_index - start_index;
    span = span / quickness + 1;

    uint8_t brightness = 255;
    for( int i = start_index; i < stop_index; i++) {
        leds[i] = ColorFromPalette(
            currentPalette,
            palette_start_index,
            brightness);
        // only on some pixels will we increment
        if (i % span == 0){
            palette_start_index += 1;
        }
    }
}

void fill_range_with_glitter(int start_index, int stop_index, fract8 chance_of_glitter)
{
    // does what it says on the tin.
    // if you're gonna call this many times then set chance_of_glitter low.
    for( int i = start_index; i < stop_index; i++) {
        if( random8() < chance_of_glitter) {
            leds[i] += CRGB::White;
          }
    }
}

void fireworks()
{
    // pick a random spot, expand pattern out from it to random size, apply some glitter to the
    // patterned region while fading out.
    // just kidding, expand from the center to the edges of the strip.
    // random doesn't seem to work here. other functions are fine though.

    // the higher this is, the slower it runs
    int slowness = 3;

    // higher = faster initial spread. 3 * slowness feels about right
    int blast = 10;

    // fade should be about twice as long as glitter
    int glitter_duration = 12;
    int fade_duration = 20;

    // keep this low or it'll be real shiny
    fract8 chance_of_glitter = 5;

    // how wide a region we draw at the outer limits of the blast
    uint8_t blast_width = 10;

    uint8_t center;
    uint8_t width;

    fadeToBlackBy( leds, NUM_LEDS, 80);

    // start a new explosion
    if (state == 0)
    {
        // for some fuckass reason 'random' is giving me very small numbers here.
        // center = random(max_width, NUM_LEDS-max_width);
        // doing clever shit like this doesn't work either
        // center = millis() % NUM_LEDS;
        // width = palette_start_index % (max_width-min_width) + min_width;
        width = 60;
        center = 60;
    }

    if ((state / slowness) < width)
    {
        // explosion is fast
        // fill_range_from_palette_adaptive(center - (state / slowness), center + (state / slowness));
        fill_range_from_palette(
            center + (state / slowness) - blast_width,
            center + (state / slowness));
        fill_range_from_palette_adaptive(
            center - (state / slowness),
            center - (state / slowness) + blast_width);
        state += blast;
    }
    else if ((state / slowness) < (width + glitter_duration))
    {
        // glitter doesn't last long either
        fill_range_with_glitter(center - width, center + width, chance_of_glitter);
        state++;
    }
    else if ((state / slowness) < (width + glitter_duration + fade_duration))
    {
        // then we fade out
        state++;
    }
    else
    {
        state = 0;
    }
}

void discontinuous_random_walk()
{
    // randomly slide a palette around on the strip and fade the tail.
    // and whiten the head of the slider.

    fadeToBlackBy( leds, NUM_LEDS, 80);
    // we have a start position and an end position


    // find positions that are not the same
    if (random_start == random_stop){
        random_start = random8() % (NUM_LEDS - compact_width - 1) + 1;
        random_stop = random8() % (NUM_LEDS - compact_width - 1) + 1;
    }

    // slide em
    if (random_start < random_stop){
        fill_range_from_palette(random_start, random_start + compact_width);
        random_start++;
        leds[random_start + compact_width] += CRGB::White;
    }

    if (random_start > random_stop){
        fill_range_from_palette(random_start, random_start+compact_width);
        random_start--;
        leds[random_start] += CRGB::White;
    }

}

void continuous_random_walk()
{
    // as above but new start point is the old stop point.
    // seizure mode!

    fadeToBlackBy( leds, NUM_LEDS, 80);
    // we have a start position and an end position

    // find positions that are not the same.
    // note we draw in the region "above" the start point.
    if (random_start == random_stop){
        random_stop = random8() % (NUM_LEDS - compact_width - 1) + 1;
    }

    // slide em
    if (random_start < random_stop){
        fill_range_from_palette(random_start, random_start + compact_width);
        random_start++;
        leds[random_start + compact_width] += CRGB::White;
    }

    if (random_start > random_stop){
        fill_range_from_palette(random_start, random_start+compact_width);
        random_start--;
        leds[random_start] += CRGB::White;
    }
}

void random_gap()
{
    // like the continuous random walk but we'll draw in the gap between the end points.
    // no whitening.
    // this one needs the adaptive palatte fill function.

    // we're gonna (build in the option to) speed this one up
    int slowness = 25;
    int increment;

    fadeToBlackBy( leds, NUM_LEDS, 80);

    // find positions that are not the same.
    // note we draw in the region "above" the start point.
    if (random_start == random_stop){
        random_stop = random8() % NUM_LEDS;
    }

    // slide em
    if (random_start < random_stop){
        increment = (random_stop - random_start) / slowness + 1;
        // fill_range_from_palette(random_start, random_stop);
        fill_range_from_palette_adaptive(random_start, random_stop);
        random_start += increment;
    }

    if (random_start > random_stop){
        increment = (random_start - random_stop) / slowness + 1;
        // fill_range_from_palette(random_stop, random_start);
        fill_range_from_palette_adaptive(random_stop, random_start);
        random_start -= increment;
    }
}
