#ifndef VISION_3223_H
#define VISION_3223_H

#include "WPILib.h"
#include "Vision/RGBImage.h"
#include "Vision/BinaryImage.h"
#include "Math.h"

namespace Vision
{
typedef struct Scores
{
    double rectangularity;
    double aspectRatioVertical;
    double aspectRatioHorizontal;
};
typedef struct TargetReport
{
    int verticalIndex;
    int horizontalIndex;
    bool Hot;
    double totalScore;
    double leftScore;
    double rightScore;
    double tapeWidthScore;
    double verticalScore;
    double distance;
};
typedef struct Aim
{
    double rotDelta;
    double dist;
} Aim;

Aim analyze(ColorImage *image);

double computeDistance(BinaryImage *image,ParticleAnalysisReport *report);
double
scoreAspectRatio(BinaryImage *image,ParticleAnalysisReport *report,bool vertical);
bool scoreCompare(Scores scores,bool vertical);
double scoreRectangularity(ParticleAnalysisReport *report);
double ratioToScore(double ratio);
bool hotOrNot(TargetReport target);
}

#endif
