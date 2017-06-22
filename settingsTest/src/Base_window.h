#pragma once

#include "ofUtils.h"

#include <QWidget>
#include <QSettings>
#include <QStandardPaths>
#include <QFileInfo>

#include<iostream>
using namespace std;

class Base_window : public QWidget {
public:
	Base_window(QWidget *parent = Q_NULLPTR): QWidget(parent)
	{
		saved = false;
		restored = false;
	}
	~Base_window() {}

	void hideEvent(QHideEvent *event) override {
		saveGeometryPrivate();
		QWidget::hideEvent(event);
	};
	void showEvent(QShowEvent *event) override {
		loadGeometryPrivate();
		QWidget::showEvent(event);
	};
	void closeEvent(QCloseEvent *event) override {
		saveGeometryPrivate();
		QWidget::closeEvent(event);
	};
	virtual void saveBaseSettings()
	{
//		cout << "saving to :" << endl << filePath.toStdString() << endl;
		p_settings->beginGroup(this->objectName());
		p_settings->setValue("widgetGeometry", this->parentWidget()->geometry());
		p_settings->endGroup();
	}
	virtual void loadBaseSettings()
	{
		QString m_path = QString::fromStdString(ofToDataPath("settings"));
		QString m_filename = this->objectName() + "_settings.ini";
		filePath = m_path + "/" + m_filename;
		p_settings = new QSettings(m_path + "/" + m_filename, QSettings::IniFormat);
//		cout << "loading from:" << endl << filePath.toStdString() << endl;

		QFileInfo check_file(filePath);
		if (check_file.exists() && check_file.isFile()) {
			p_settings->beginGroup(this->objectName());
			{// geometry
				auto value = p_settings->value("widgetGeometry", this->parentWidget()->geometry()).toRect();
//				cout << "setting geometry to " << value.x() << " " << value.y() << endl;
				this->parentWidget()->setGeometry(value);
			}
			p_settings->endGroup();
		}
		else {
			cout << "file does not exist." << endl;
		}
	}
	QString filePath;
	QSettings * p_settings;

	// to inherit
	virtual void saveSettings() {
		saveBaseSettings();
	};
	virtual void loadSettings() {
		loadBaseSettings();
	};

	void beginSettings() {
		p_settings->beginGroup(this->objectName());
	};
	void endSettings() {
		p_settings->endGroup();
	}

private:
	void saveGeometryPrivate() {
		if (saved == false) {
			saveSettings();
			saved = true;
		}
	}
	void loadGeometryPrivate() {
		if (restored == false) {
			loadSettings();
			restored = true;
		}
	}
	bool saved;
	bool restored;
};