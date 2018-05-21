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

    FileDialog {
        id: fileDialog
        title: qsTr("请选择文件")
        folder: shortcuts.home
        onAccepted: {
            var path = fileDialog.fileUrl.toString();
            path= path.replace(/^(file:\/{3})|(qrc:\/{2})|(http:\/{2})/,"");
            // unescape html codes like '%23' for '#'
            var cleanPath = decodeURIComponent(path);
            textFieldPath.text = cleanPath;
            $replica.read(cleanPath);
        }
    }

    ColumnLayout{
        anchors.fill: parent
        anchors.margins: 10
        Label{
            Layout.fillWidth: true
            text: qsTr("文件路径：")
        }
        RowLayout{
            Layout.fillWidth: true

            TextField{
                id: textFieldPath
                Layout.fillWidth: true
            }
            Button{
                id: buttonSelect
                text: qsTr("选择文件...")
                onClicked: {
                    fileDialog.open();
                }
            }
        }
        Label{
            Layout.fillWidth: true
            text: qsTr("文件内容：")
        }
        TextArea{
            id: textAreaContent
            Layout.fillWidth: true
            Layout.fillHeight: true
            readOnly: true
            //text: $replica.content
        }
    }
}
