/**
 * @file
 * @brief Header file for RendererBase class
 * @author Duzy Chan <code@duzy.info>
 *
 * @section LICENSE
 *
 * Copyright (c) 2008-2013 OpenShot Studios, LLC
 * (http://www.openshotstudios.com). This file is part of
 * OpenShot Library (http://www.openshot.org), an open-source project
 * dedicated to delivering high quality video editing and animation solutions
 * to the world.
 *
 * OpenShot Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OpenShot Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OpenShot Library.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef OPENSHOT_RENDERER_BASE_H
#define OPENSHOT_RENDERER_BASE_H

#include <tr1/memory>

namespace openshot
{
    class Frame;

    /**
     *  @brief The pixel format supported by renderers.
     *
     *  Currently only RGB_888 is supported.
     *
     *  @see QuantumType
     */
    enum PixelFormat {
	RGB_888,
    };

    /**
     * @brief This is the base class of all Renderers in libopenshot.
     *
     * Renderers are responsible for rendering images of a video onto a
     * display device.
     */
    class RendererBase
    {
	unsigned char *buffer;

    public:

	/// Paint(render) a video Frame.
	void paint(const std::tr1::shared_ptr<Frame> & frame);

    protected:
	RendererBase();
	virtual ~RendererBase();
	
	virtual void render(PixelFormat format, int width, int height, int bytesPerLine, unsigned char *data) = 0;
    };

}

#endif