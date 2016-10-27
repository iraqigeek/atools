/*****************************************************************************
* Copyright 2015-2016 Alexander Barthel albar965@mailbox.org
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#ifndef ATOOLS_FS_SC_SIMCONNECTAIRPLANE_H
#define ATOOLS_FS_SC_SIMCONNECTAIRPLANE_H

#include "geo/pos.h"
#include "fs/sc/simconnectdatabase.h"

#include <QString>
#include <QDateTime>

class QIODevice;

namespace atools {
namespace fs {
namespace sc {

class SimConnectHandler;

// quint16
enum Flag
{
  NONE = 0x00,
  ON_GROUND = 0x01,
  IN_CLOUD = 0x02,
  IN_RAIN = 0x04,
  IN_SNOW = 0x08
};

Q_DECLARE_FLAGS(Flags, Flag);
Q_DECLARE_OPERATORS_FOR_FLAGS(atools::fs::sc::Flags);

enum CategoryEnum
{
  AIRPLANE,
  HELICOPTER,
  BOAT,
  GROUNDVEHICLE,
  CONTROLTOWER,
  SIMPLEOBJECT,
  VIEWER
};

Q_DECLARE_FLAGS(Category, CategoryEnum);

/*
 * Base aircraft that is used to transfer across network links. For user and AI aircraft.
 */
class SimConnectAircraft :
  public SimConnectDataBase
{
public:
  SimConnectAircraft();
  SimConnectAircraft(const SimConnectAircraft& other);
  virtual ~SimConnectAircraft();

  virtual void read(QDataStream& in);
  virtual void write(QDataStream& out) const;

  // fs data ----------------------------------------------------

  const QString& getAirplaneTitle() const
  {
    return airplaneTitle;
  }

  const QString& getAirplaneModel() const
  {
    return airplaneModel;
  }

  const QString& getAirplaneRegistration() const
  {
    return airplaneReg;
  }

  atools::geo::Pos& getPosition()
  {
    return position;
  }

  const atools::geo::Pos& getPosition() const
  {
    return position;
  }

  float getHeadingDegTrue() const
  {
    return headingTrue;
  }

  float getHeadingDegMag() const
  {
    return headingMag;
  }

  float getGroundSpeedKts() const
  {
    return groundSpeed;
  }

  float getIndicatedSpeedKts() const
  {
    return indicatedSpeed;
  }

  float getVerticalSpeedFeetPerMin() const
  {
    return verticalSpeed;
  }

  const QString& getAirplaneType() const
  {
    return airplaneType;
  }

  const QString& getAirplaneAirline() const
  {
    return airplaneAirline;
  }

  const QString& getAirplaneFlightnumber() const
  {
    return airplaneFlightnumber;
  }

  float getIndicatedAltitudeFt() const
  {
    return indicatedAltitude;
  }

  float getTrueSpeedKts() const
  {
    return trueSpeed;
  }

  float getMachSpeed() const
  {
    return machSpeed;
  }

  Flags getFlags() const
  {
    return flags;
  }

  Flags& getFlags()
  {
    return flags;
  }

  float getTrackDegMag() const
  {
    return trackMag;
  }

  float getTrackDegTrue() const
  {
    return trackTrue;
  }

  float getMagVarDeg() const
  {
    return magVar;
  }

private:
  friend class atools::fs::sc::SimConnectHandler;

  QString airplaneTitle, airplaneType, airplaneModel, airplaneReg,
          airplaneAirline, airplaneFlightnumber;

  atools::geo::Pos position;
  float headingTrue = 0.f, headingMag = 0.f, groundSpeed = 0.f, indicatedAltitude = 0.f,
        indicatedSpeed = 0.f, trueSpeed = 0.f,
        machSpeed = 0.f, verticalSpeed = 0.f;

  float trackMag = 0.f, trackTrue = 0.f, magVar = 0.f;

  Category category;
  Flags flags = atools::fs::sc::NONE;
};

} // namespace sc
} // namespace fs
} // namespace atools

Q_DECLARE_METATYPE(atools::fs::sc::SimConnectAircraft);

Q_DECLARE_TYPEINFO(atools::fs::sc::SimConnectAircraft, Q_MOVABLE_TYPE);

#endif // ATOOLS_FS_SIMCONNECTAIRPLANE_H