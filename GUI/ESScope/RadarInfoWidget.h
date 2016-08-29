#ifndef SIDECAR_GUI_ESSCOPE_RADARINFOWIDGET_H // -*- C++ -*-
#define SIDECAR_GUI_ESSCOPE_RADARINFOWIDGET_H

#include "QtCore/QBasicTimer"
#include "QtGui/QWidget"

#include "Messages/PRIMessage.h"

namespace Logger { class Log; }

namespace Ui { class RadarInfoWidget; }
namespace SideCar {
namespace Time { class TimeStamp; }
namespace GUI {
namespace ESScope {

class App;
class RadarSettings;

/** QToolBar widget that shows the azimuth and message time of the last message processed by the application.
    Updates to the widget come from the showMessageInfo() slot.

    This class performs a lot of data caching in order to minimize the time
    spent in showMessageInfo(), and to speed up widget updates. Within
    showMessageInfo(), the class takes in the raw data, and sets various
    boolean flags if the raw data is different than what was seen before. An
    internal timer periodically checks the boolean flags to see if the widget
    needs an update. If so, the makeLabel() routine will rebuild a QString
    value for the widget's label text. The RadarInfoWidget class keesp around
    the individual QString objects associated with raw values so that they only
    get regenerated by raw value changes.
*/
class RadarInfoWidget : public QWidget
{
    Q_OBJECT
    using Super = QWidget;
public:

    static Logger::Log& Log();

    /** Constructor. Creates and initializes window widgets.
     */
    RadarInfoWidget(QWidget* parent = 0);

public slots:

    void showMessageInfo(const Messages::PRIMessage::Ref& msg);

    void setTilt(double value);

    void setRotation(double value);

    void refresh();

private slots:

    void refreshTilt();

    void refreshRotation();

private:

    QString makeLabel();

    void timerEvent(QTimerEvent* event);

    Ui::RadarInfoWidget* gui_;
    App* app_;
    RadarSettings* radarSettings_;
    QBasicTimer updateTimer_;
    QString alphaText_;
    QString betaText_;
    QString timeText_;
    QString tiltText_;
    QString rotationText_;
    double alpha_;
    double beta_;
    double irigTime_;
    Time::TimeStamp createdTime_;
    double tilt_;
    double rotation_;
    bool hasIRIGTime_;
    bool updateAlpha_;
    bool updateBeta_;
    bool updateTime_;

    static const int kUpdateInterval;
};

} // end namespace ESScope
} // end namespace GUI
} // end namespace SideCar

/** \file
 */

#endif
