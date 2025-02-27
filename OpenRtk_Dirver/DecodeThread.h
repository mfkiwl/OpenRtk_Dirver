#pragma once

#include <QThread>
#include <QTime>
#include <QList>
#include "ins401.h"
#include "rtk330la_decoder.h"
#include "E2E_protocol.h"
#include "NPOS122_decoder.h"
#include "StaticAnalysis.h"

//��UI��˳��һ��
enum emDecodeFormat {
	emDecodeFormat_OpenRTK330LI,
	emDecodeFormat_RTK330LA,
	emDecodeFormat_Ins401,
	emDecodeFormat_Mixed_Raw,
	emDecodeFormat_Imu,
	emDecodeFormat_E2E_Protocol,
	emDecodeFormat_RTCM_EPVT,
	emDecodeFormat_Convbin,
	emDecodeFormat_RTCM_2_HEX,
	emDecodeFormat_Beidou,
	emDecodeFormat_NPOS112,
	emDecodeFormat_ST_RTCM,
};

class DecodeThread : public QThread
{
	Q_OBJECT

public:
	DecodeThread(QObject *parent);
	~DecodeThread();
	void run();
	void stop();
	void setFileFormat(int format);
	void setFileName(QString file);
	void setShowTime(bool show);
	void setKmlFrequency(int frequency);
	void setDateTimeStr(QString time);
	void setDateTime(QDateTime time);
	void setMIFileSwitch(bool write);
protected:
	void makeOutPath(QString filename);
	void decode_openrtk_user();
	void decode_openrtk_inceptio();
	void decode_rtk330la();
	void decode_mixed_raw();
	void decode_imu();
	void decode_ins401();
	void decode_e2e_protocol();
	void decode_rtcm_epvt();
	void decode_rtcm_convbin();
	void decode_rtcm_2_hex();
	void decode_beidou();
	void decode_npos112();
	void decode_st_rtcm();
	void decode_lg69t_rtcm();
private:
	bool m_isStop;
	int m_FileFormat;
	QString m_FileName;
	QString m_OutBaseName;
	QTime m_TimeCounter;
	Ins401_Tool::Ins401_decoder* ins401_decoder;
	RTK330LA_Tool::Rtk330la_decoder* rtk330la_decoder;
	E2E::E2E_protocol* e2e_deocder;
	NPOS122_Tool::NPOS122_decoder* npos122_decoder;
	bool m_show_time;
	int ins_kml_frequency;
	QString m_datatime_str;
	QDateTime m_datatime;
public:
	bool m_static_point_ecp;
	StaticAnalysis* m_StaticAnalysis;
signals:
	void sgnProgress(int present, int msecs);
	void sgnFinished();
};
