import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.12
import Models 1.0

Window {
    id: root
    visible: true
    width: 800
    height: 600
    title: qsTr("Nested Models")

    readonly property int defaultSpacing: 5
    property var urls: [
        "qt.io",
        "kde.org",
        "linux.org",
        "keepassxc.org"
    ]

    TabBar {
        id: tabBar

        Repeater {
            model: root.urls

            TabButton {
                text: modelData
                width: 150
            }
        }
    }

    StackLayout {
        anchors.fill: parent
        anchors.topMargin: tabBar.height + defaultSpacing
        currentIndex: tabBar.currentIndex

        Repeater {
            model: root.urls

            Item {
                ListView {
                    model: SubModel {
                        source: modelData
                    }
                    anchors.fill: parent

                    delegate: Text {
                        text: display
                    }
                }
            }
        }
    }

}
