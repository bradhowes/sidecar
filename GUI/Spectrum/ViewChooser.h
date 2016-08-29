#ifndef SIDECAR_GUI_SPECTRUM_VIEWCHOOSER_H // -*- C++ -*-
#define SIDECAR_GUI_SPECTRUM_VIEWCHOOSER_H

#include "QtGui/QWidget"

class QComboBox;

namespace SideCar {
namespace GUI {
namespace Spectrum {

class ViewEditor;

class ViewChooser : public QWidget
{
    Q_OBJECT
    using Super = QWidget;
public:

    ViewChooser(ViewEditor* viewEditor, QWidget* parent = 0);

private slots:

    void presetNamesChanged(const QStringList& names);

private:
    QComboBox* chooser_;
};

} // end namespace Spectrum
} // end namespace GUI
} // end namespace SideCar

#endif
