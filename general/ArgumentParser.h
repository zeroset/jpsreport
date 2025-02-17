/**
 * \file        ArgumentParser.cpp
 * \date        Oct 10, 2014
 * \version     v0.7
 * \copyright   <2009-2015> Forschungszentrum Jülich GmbH. All rights reserved.
 *
 * \section License
 * This file is part of JuPedSim.
 *
 * JuPedSim is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * JuPedSim is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with JuPedSim. If not, see <http://www.gnu.org/licenses/>.
 *
 * \section Description
 * The ArgumentParser class define functions reading the input parameters from initial files.
 *
 *
 **/
#ifndef ARGUMENTPARSER_H_
#define ARGUMENTPARSER_H_

#include <string>
#include <vector>
#include "Macros.h"
#include "../methods/MeasurementArea.h"

#include <boost/geometry/geometry.hpp>
#include <boost/geometry/geometries/point_xy.hpp>
#include <boost/geometry/geometries/polygon.hpp>
#include <boost/geometry/geometries/adapted/c_array.hpp>
#include <filesystem>

namespace fs = std::filesystem;

using namespace boost::geometry;
typedef model::d2::point_xy<double, cs::cartesian> point_2d;
typedef model::polygon<point_2d> polygon_2d;


class OutputHandler;
extern OutputHandler* Log;

class ArgumentParser {
private:

     fs::path _geometryFileName;
     fs::path _errorLogFile;
     fs::path _trajectoriesLocation;
     fs::path _trajectoriesFilename;
     fs::path _projectRootDir;
     fs::path _outputDir;

     FileFormat _fileFormat;
     std::vector<fs::path> _trajectoriesFiles;

     std::string _vComponent;
     bool _IgnoreBackwardMovement;
     bool _isMethodA;
     bool _isMethodB;
     bool _isMethodC;
     bool _isMethodD;
     bool _isMethodI;
     bool _isMethodJ;
     bool _isCutByCircle;
     double _cutRadius;
     int _circleEdges;
     bool _isOneDimensional;
     bool _isGetProfile;
     double _steadyStart;
     double _steadyEnd;
     int _delatTVInst;

     std::vector<int> _areaIDforMethodA;
     std::vector<int> _areaIDforMethodB;
     std::vector<int> _areaIDforMethodC;
     std::vector<int> _areaIDforMethodD;
     std::vector<int> _areaIDforMethodI;
     std::vector<int> _areaIDforMethodJ;
     float _grid_size_X;
     float _grid_size_Y;
     int _log;
     std::vector<int> _start_frames_MethodD;
     std::vector<int> _stop_frames_MethodD;
     std::vector<int> _start_frames_MethodI;
     std::vector<int> _stop_frames_MethodI;
     std::vector<int> _start_frames_MethodJ;
     std::vector<int> _stop_frames_MethodJ;
     std::vector<bool> _individual_FD_flags;
     std::vector<int> _timeIntervalA;


     std::map <int, MeasurementArea*> _measurementAreas;
     void Usage(const std::string file);

public:
     // Konstruktor
     ArgumentParser();
     const fs::path& GetTrajectoriesFilename() const;
     const std::vector<fs::path>& GetTrajectoriesFiles() const;
     const fs::path& GetTrajectoriesLocation() const;
     const FileFormat& GetFileFormat() const;
     const fs::path& GetGeometryFilename() const;
     const fs::path& GetErrorLogFile() const;
     const fs::path& GetProjectRootDir() const;
     const fs::path& GetOutputLocation() const;

     double GetLengthMeasurementArea() const;
     polygon_2d GetMeasureArea() const;
     double GetLineStartX() const;
     double GetLineStartY() const;
     double GetLineEndX() const;
     double GetLineEndY() const;

     std::string GetVComponent() const;
     bool GetIgnoreBackwardMovement() const;
     int GetDelatT_Vins() const;
     std::vector<int> GetTimeIntervalA() const;
     bool GetIsMethodA() const;
     bool GetIsMethodB() const;
     bool GetIsMethodC() const;
     bool GetIsMethodD() const;
     bool GetIsMethodI() const;
     bool GetIsMethodJ() const;
     std::vector<int> GetAreaIDforMethodA() const;
     std::vector<int> GetAreaIDforMethodB() const;
     std::vector<int> GetAreaIDforMethodC() const;
     std::vector<int> GetAreaIDforMethodD() const;
     std::vector<int> GetAreaIDforMethodI() const;
     std::vector<int> GetAreaIDforMethodJ() const;
     std::vector<int> GetStartFramesMethodD() const;
     std::vector<int> GetStopFramesMethodD() const;
     std::vector<int> GetStartFramesMethodI() const;
     std::vector<int> GetStopFramesMethodI() const;
     std::vector<int> GetStartFramesMethodJ() const;
     std::vector<int> GetStopFramesMethodJ() const;
     std::vector<bool> GetIndividualFDFlags() const;
     bool GetIsCutByCircle() const;
     double GetCutRadius() const;
     int GetCircleEdges() const;
     bool GetIsOutputGraph() const;
     bool GetIsOneDimensional() const;
     bool GetIsIndividualFD() const;
     polygon_2d GetAreaIndividualFD() const;
     double GetSteadyStart() const;
     double GetSteadyEnd() const;
     bool GetIsGetProfile() const;
     float GetGridSizeX() const;
     float GetGridSizeY() const;
     int GetLog() const;
     bool ParseArgs(int argc, char **argv);
     void SetErrorLogFile(fs::path errorLogFile);
     void SetLog(int log);
     MeasurementArea* GetMeasurementArea(int id);

     /**
      * parse the initialization file
      * @param inifile
      */
     bool ParseIniFile(const std::string& inifile);
};

#endif /*ARGPARSER_H_*/
