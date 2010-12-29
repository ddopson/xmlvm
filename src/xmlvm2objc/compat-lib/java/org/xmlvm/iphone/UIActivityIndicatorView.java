/* Copyright (c) 2002-2011 by XMLVM.org
 *
 * Project Info:  http://www.xmlvm.org
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
 * License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
 * USA.
 */

package org.xmlvm.iphone;

import org.xmlvm.XMLVMSkeletonOnly;
import org.xmlvm.iphone.internal.renderer.UIActivityIndicatorViewRenderer;

@XMLVMSkeletonOnly
public class UIActivityIndicatorView extends UIView {

    private int                             activityIndicatorViewStyle = UIActivityIndicatorViewStyle.White;
    private boolean                         hidesWhenStopped           = true;
    private UIActivityIndicatorViewRenderer renderer;


    public UIActivityIndicatorView() {
        this(UIActivityIndicatorViewStyle.White);
    }

    public UIActivityIndicatorView(int uiActivityIndicatorViewStyle) {
        renderer = new UIActivityIndicatorViewRenderer(this);
        xmlvmSetRenderer(renderer);
        this.setActivityIndicatorViewStyle(uiActivityIndicatorViewStyle);
    }

    public void setActivityIndicatorViewStyle(int style) {
        this.activityIndicatorViewStyle = style;
    }

    public int getActivityIndicatorViewStyle() {
        return this.activityIndicatorViewStyle;
    }

    public void setHidesWhenStopped(boolean flag) {
        this.hidesWhenStopped = flag;
    }

    public boolean getHidesWhenStopped() {
        return this.hidesWhenStopped;
    }

    public void startAnimating() {
        this.renderer.startAnimating();
    }

    public void stopAnimating() {
        this.renderer.stopAnimating();
    }

}
