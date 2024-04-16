import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

import MohsenCpp
import MohsenKit as UiKit

ApplicationWindow {
    visible: true
    width: 790
    height: 500
    title: "Camera Capture"

    CameraCapture {
        id: capture
        onNewDataGenerated: newData => {
                                plot.newFrameArrived(newData)
                            }
    }

    MVideoPlayerItem {
        id: plot
        anchors.fill: parent
    }

    Row {
        id: topRow
        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 10
        spacing: 10

        UiKit.MButton {
            text: "Start"
            onClicked: {
                if (!capture.running) {
                    capture.start()
                }
            }
        }

        UiKit.MButton {
            text: "Stop"
            onClicked: {
                capture.stop()
            }
        }
    }
}
