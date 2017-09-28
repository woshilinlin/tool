#ifndef IMAGETOOLS_H
#define IMAGETOOLS_H

#include <opencv2/opencv.hpp>
#include <QImage>

/*!
 * \brief The Imagetools class 　QImage与cv::Mat之间的转换类
 */
class Imagetools
{
public:
    Imagetools();

    /*!
     * \brief cvMat2QImage  cv::Mat转换为QImage
     * \param mat  需转换的cv::Mat
     * \param clone  是否复制
     * \return cv::Mat转换之后的QImage
     */
    static QImage cvMat2QImage(const cv::Mat &mat, bool clone = false);

    /*!
     * \brief QImage2cvMat  QImage转换为cv::Mat
     * \param image  需转换的QImage
     * \param clone  是否复制
     * \return QImage转换之后的cv::Mat
     */
    static cv::Mat QImage2cvMat(const QImage &image, bool clone = false);
};

#endif // IMAGETOOLS_H
