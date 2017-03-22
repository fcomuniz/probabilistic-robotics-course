classdef Simulation < handle
    properties
        u
        x
        z
        xHat
        Pk
        model
        filter
        dynamicPlot
        Tplot
        axisSizes
    end
    methods
        function obj =  Simulation(model,filter,u)
            obj.u = u;
            obj.x = cell(length(u)+1,1);
            obj.xHat = cell(length(u)+1,1);
            obj.Pk = cell(length(u)+1,1);
            obj.z = cell(length(u),1);
            obj.model=model;
            obj.filter = filter;
            
            obj.dynamicPlot = 1;
            obj.Tplot = 0.5;
            obj.axisSizes = [-10,10,-10,10];
        end
        function z = generateObservation(obj,x)
            z = mvnrnd(obj.model.C*x,obj.model.R);
        end
        function simulate(obj)
            axisValues = [obj.axisSizes(1)+obj.model.m0(1),obj.axisSizes(2)+obj.model.m0(1),obj.axisSizes(3)+obj.model.m0(2),obj.axisSizes(4)+obj.model.m0(2)];
            obj.x{1} = mvnrnd(obj.model.m0',obj.model.P0)';
            obj.xHat{1} = obj.filter.m;
            obj.Pk{1} = obj.filter.P;
            for index = 1:length(obj.u)
                obj.x{index+1} = obj.model.A*obj.x{index}+obj.model.B*obj.u{index};
                obj.x{index+1} = mvnrnd(obj.x{index+1}',obj.model.Q)';
                [obj.xHat{index+1},obj.Pk{index+1}] = obj.filter.updateStep(obj.u{index});
                if obj.dynamicPlot
                    figure(1)
                    clf()
                    title('After Update');
                    hold on
                    plot(obj.x{index+1}(1),obj.x{index+1}(2),'r*');
                    plot(obj.xHat{index+1}(1),obj.xHat{index+1}(2),'b*');
                    legend('Actual Position', 'Estimated Position');
                    obj.plot2DGaussian(obj.xHat{index+1},obj.Pk{index+1});
                    axis(axisValues);
                    drawnow
                    pause(obj.Tplot);
                end
                    
                obj.z{index} = obj.generateObservation(obj.x{index+1});
                [obj.xHat{index+1},obj.Pk{index+1}] = obj.filter.updateStep(obj.z{index});
                if obj.dynamicPlot
                    figure(1)
                    clf()
                    title('After Filtering Step');
                    hold on
                    plot(obj.x{index+1}(1),obj.x{index+1}(2),'r*');
                    plot(obj.xHat{index+1}(1),obj.xHat{index+1}(2),'b*');
                    if length(obj.z{index}>=2)
                        plot(obj.z{index}(1),obj.z{index}(2),'g*');
                        legend('Actual Position', 'Estimated Position','Observation');
                    else
                        legend('Actual Position', 'Estimated Position');
                    end
                    obj.plot2DGaussian(obj.xHat{index+1},obj.Pk{index+1});
                    axis(axisValues);
                    drawnow
                    pause(obj.Tplot);
                end
                
                   
            end
            figure(2)
            clf()
            hold on;
            title('Estimated Trajectory vs Real Trajectory');
            xState = zeros(length(obj.u)+1,1);
            yState = zeros(length(obj.u)+1,1);
            xFilter = zeros(length(obj.u)+1,1);
            yFilter = zeros(length(obj.u)+1,1);
            xObservation = zeros(length(obj.u),1);
            yObservation = zeros(length(obj.u),1);

            xState(1) = obj.x{1}(1);
            yState(1) = obj.x{1}(2);
            xFilter(1) = obj.xHat{1}(1);
            yFilter(1) = obj.xHat{1}(2);
            for index = 1:length(obj.u)
                xState(index+1) = obj.x{index+1}(1);
                yState(index+1) = obj.x{index+1}(2);
                xFilter(index+1) = obj.xHat{index+1}(1);
                yFilter(index+1) = obj.xHat{index+1}(2);
                if(length(obj.z{index})>=2)
                    xObservation(index) = obj.z{index}(1);
                    yObservation(index) = obj.z{index}(2);
                end
            end
            plot(xState,yState,'r');
            plot(xFilter,yFilter,'b');
            if(length(obj.z{1})>=2)
                plot(xObservation,yObservation,'g*');
                legend('Actual Trajectory', 'Estimated Trajectory','Observations');
            else
                legend('Actual Trajectory', 'Estimated Trajectory');
            end
            
        end
        function plot2DGaussian(obj,mu,Sigma,confidence)
            if(nargin<4)
                confidence = 0.9545;
            end
            hold on;
            
            covariance = Sigma(1:2,1:2);
            [eigenvec, eigenval ] = eig(covariance);
            [largest_eigenvec_ind_c, r] = find(eigenval == max(max(eigenval)));
            largest_eigenvec = eigenvec(:, largest_eigenvec_ind_c);
            largest_eigenval = max(max(eigenval));
            if(largest_eigenvec_ind_c == 1)
                smallest_eigenval = max(eigenval(:,2));
            else
                smallest_eigenval = max(eigenval(:,1));
            end
            angle = atan2(largest_eigenvec(2), largest_eigenvec(1));
            if(angle < 0)
                angle = angle + 2*pi;
            end
            avg = mu(1:2)';
            
            chisquare_val = sqrt(chi2inv(confidence,2));
            theta_grid = linspace(0,2*pi);
            phi = angle;
            X0=avg(1);
            Y0=avg(2);
            a=chisquare_val*sqrt(largest_eigenval);
            b=chisquare_val*sqrt(smallest_eigenval);
            ellipse_x_r  = a*cos( theta_grid );
            ellipse_y_r  = b*sin( theta_grid );
            R = [ cos(phi) sin(phi); -sin(phi) cos(phi) ];
            r_ellipse = [ellipse_x_r;ellipse_y_r]' * R;
            
            plot(r_ellipse(:,1) + X0,r_ellipse(:,2) + Y0,'-','LineWidth',1,...
                'Color',[0.5 0 0.5]);
            
            hold off;
        end
    end
end