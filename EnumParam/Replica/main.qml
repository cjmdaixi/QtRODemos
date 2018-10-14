import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("QtRO Introduction: Replica")


    property int fe: $replica.fe
    onFeChanged: {
        console.log("fe changed:", fe);
    }

    Connections{
        target: $replica
        onStatusRenewed:{
            console.log("status renewed:", newStatus);
        }
    }

    Button{
        text: "click"
        anchors.centerIn: parent
        onClicked: {
            $replica.fe = 1;
        }
    }
}
