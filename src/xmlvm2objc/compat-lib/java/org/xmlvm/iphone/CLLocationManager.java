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

import java.util.Set;
import org.xmlvm.XMLVMSkeletonOnly;

@XMLVMSkeletonOnly
public class CLLocationManager extends NSObject {

    private CLLocationManagerDelegate delegate;
    private double                    distanceFilter                  = CLDistanceFilter.None;
    private double                    desiredAccuracy                 = CLLocationAccuracy.Best;
    private double                    headingFilter                   = CLHeadingFilter.None;
    private int                       headingOrientation;
    private Set<CLRegion>             monitoredRegions;
    private double                    maximumRegionMonitoringDistance = -1;
    private CLLocation                location;
    private CLHeading                 heading;
    private String                    purpose;


    public static boolean locationServicesEnabled() {
        return false;
    }

    public static boolean significantLocationChangeMonitoringAvailable() {
        return false;
    }

    public static boolean headingAvailable() {
        return false;
    }

    public static boolean regionMonitoringAvailable() {
        return false;
    }

    public static boolean regionMonitoringEnabled() {
        return false;
    }

    public void startUpdatingLocation() {
        // TODO : Java implementation
    }

    public void stopUpdatingLocation() {
        // TODO : Java implementation
    }

    public void startMonitoringSignificantLocationChanges() {
        // TODO : Java implementation
    }

    public void stopMonitoringSignificantLocationChanges() {
        // TODO : Java implementation
    }

    public void startUpdatingHeading() {
        // TODO : Java implementation
    }

    public void stopUpdatingHeading() {
        // TODO : Java implementation
    }

    public void dismissHeadingCalibrationDisplay() {
        // TODO : Java implementation
    }

    public void startMonitoringForRegion(CLRegion region, double accuracy) {
        // TODO : Java implementation
    }

    public void stopMonitoringForRegion(CLRegion region) {
        // TODO : Java implementation
    }

    public CLLocationManagerDelegate getDelegate() {
        return delegate;
    }

    public void setDelegate(CLLocationManagerDelegate delegate) {
        this.delegate = delegate;
    }

    public double getDesiredAccuracy() {
        return desiredAccuracy;
    }

    public void setDesiredAccuracy(double desiredAccuracy) {
        this.desiredAccuracy = desiredAccuracy;
    }

    public double getDistanceFilter() {
        return distanceFilter;
    }

    public void setDistanceFilter(double distanceFilter) {
        this.distanceFilter = distanceFilter;
    }

    public double getHeadingFilter() {
        return headingFilter;
    }

    public void setHeadingFilter(double headingFilter) {
        this.headingFilter = headingFilter;
    }

    public int getHeadingOrientation() {
        return headingOrientation;
    }

    public void setHeadingOrientation(int headingOrientation) {
        this.headingOrientation = headingOrientation;
    }

    public Set<CLRegion> getMonitoredRegions() {
        return monitoredRegions;
    }

    public double getMaximumRegionMonitoringDistance() {
        return maximumRegionMonitoringDistance;
    }

    public CLHeading getHeading() {
        return heading;
    }

    public CLLocation getLocation() {
        return location;
    }

    public String getPurpose() {
        return purpose;
    }

    public void setPurpose(String purpose) {
        this.purpose = purpose;
    }
}
