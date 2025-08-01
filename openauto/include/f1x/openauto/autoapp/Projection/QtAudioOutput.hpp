/*
*  This file is part of openauto project.
*  Copyright (C) 2018 f1x.studio (Michal Szwaj)
*
*  openauto is free software: you can redistribute it and/or modify
*  it under the terms of the GNU General Public License as published by
*  the Free Software Foundation; either version 3 of the License, or
*  (at your option) any later version.

*  openauto is distributed in the hope that it will be useful,
*  but WITHOUT ANY WARRANTY; without even the implied warranty of
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*  GNU General Public License for more details.
*
*  You should have received a copy of the GNU General Public License
*  along with openauto. If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <QAudioSink>
#include <QAudioFormat>
#include <f1x/openauto/autoapp/Projection/IAudioOutput.hpp>
#include <f1x/openauto/autoapp/Projection/SequentialBuffer.hpp>

namespace f1x
{
namespace openauto
{
namespace autoapp
{
namespace projection
{

class QtAudioOutput: public QObject, public IAudioOutput
{
    Q_OBJECT

public:
    QtAudioOutput(uint32_t channelCount, uint32_t sampleSize, uint32_t sampleRate);
    bool open() override;
    void write(aasdk::messenger::Timestamp::ValueType, const aasdk::common::DataConstBuffer& buffer) override;
    void start() override;
    void stop() override;
    void suspend() override;
    uint32_t getSampleSize() const override;
    uint32_t getChannelCount() const override;
    uint32_t getSampleRate() const override;

signals:
    void startPlayback();
    void suspendPlayback();
    void stopPlayback();

protected slots:
    void createAudioOutput();
    void onStartPlayback();
    void onSuspendPlayback();
    void onStopPlayback();

private:
    QAudioFormat audioFormat_;
    SequentialBuffer audioBuffer_;
    std::unique_ptr<QAudioSink> audioOutput_;
    bool playbackStarted_;
};

}
}
}
}
