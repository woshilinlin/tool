#ifndef IMAGETOOLS_H
#define IMAGETOOLS_H

#include <opencv2/opencv.hpp>
#include <QImage>

class Imagetools
{
public:
    Imagetools();
    static QImage cvMat2QImage(const cv::Mat &mat, bool clone = false);
    static cv::Mat QImage2cvMat(const QImage &image, bool clone = false);
};

#endif // IMAGETOOLS_H
