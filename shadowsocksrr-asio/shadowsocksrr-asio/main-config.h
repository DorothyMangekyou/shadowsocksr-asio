/*
 *  This file is part of the shadowsocksrr-asio project.
 *  shadowsocksrr-asio is a shadowsocksr implement which driven by boost.asio.
 *  Copyright (C) 2018  Akkariiin
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef BASE_CONFIG_H
#define BASE_CONFIG_H

#include <memory>

class MainConfig : public std::enable_shared_from_this<MainConfig> {
    bool inited = false;
public:
    MainConfig();

    ~MainConfig() = default;

    void loadFile(std::string path);

    void loadJsonString(std::string jsonString);

    bool analysis(/*TODO*/);

    bool isInitOk() const;

    // help function to create sub config from a sub config tree or sub config string
    // TODO
    template<typename TConfig>
    std::shared_ptr<TConfig> getConfig(/*TODO*/);

    // TODO config tree
};

template<typename TConfig>
inline std::shared_ptr<TConfig> MainConfig::getConfig(/*TODO*/) {
    auto c = std::make_shared<TConfig>();
    c->analysis(/*TODO*/);
    return c;
}


#endif    // BASE_CONFIG_H
