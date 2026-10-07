#pragma once
#include <QObject>
#include <QProcess>
namespace Jiit {
class XrayManager final : public QObject {
  Q_OBJECT
public:
  explicit XrayManager(QObject *parent = nullptr);
  void configure(bool enabled, const QString &mode, const QString &service);
  bool enabled() const { return m_enabled; }
  bool isActive() const { return m_active; }
  bool available() const { return m_available; }
  QString status() const;
  void start();
  void stop();
  void query();
signals:
  void operationFinished(const QString &action, bool ok, const QString &detail);
  void stateChanged(const QString &status);

private:
  void run(const QString &action);
  QString m_mode{"system"}, m_service{"xray.service"}, m_status{"Unknown"};
  bool m_enabled{false}, m_active{false}, m_available{true};
};
} // namespace Jiit
